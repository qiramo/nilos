#pragma once

#include <stdint.h>

#include <nilos/system/panic.h>

typedef enum: u8 {
	// Present or not
	GDT_ACCESS_PRESENT = 0b10000000,

	// Privilege levels. 0 is highest
	GDT_ACCESS_PRIVILEGE_RING_0 = 0b00000000,
	GDT_ACCESS_PRIVILEGE_RING_1 = 0b00100000,
	GDT_ACCESS_PRIVILEGE_RING_2 = 0b01000000,
	GDT_ACCESS_PRIVILEGE_RING_3 = 0b01100000,

	// Set: code or data segment. Clear: system segment
	GDT_ACCESS_CODE_DATA = 0b00010000,

	// Set: code segment. Clear: data segment
	GDT_ACCESS_EXECUTABLE = 0b00001000,

	// If data: direction: segment grow downwards
	// If code: conforming: code can be run from lower privilege segments
	GDT_ACCESS_DIRECTION_CONFORMING = 0b00000100,

	// If code: read: code can be read. Useful for constants
	// If data: write: data can be written to
	GDT_ACCESS_READ_WRITE = 0b00000010,

	// CPU will set this bit once the entry is accessed. If this segment is
	// read-only this will cause an error. Best set unless needed
	GDT_ACCESS_ACCESSED = 0b00000001,

	// Utility
	GDT_ACCESS_KERNEL_CODE = GDT_ACCESS_PRESENT | GDT_ACCESS_PRIVILEGE_RING_0 |
		GDT_ACCESS_CODE_DATA | GDT_ACCESS_EXECUTABLE | GDT_ACCESS_READ_WRITE,
	GDT_ACCESS_KERNEL_DATA = GDT_ACCESS_PRESENT | GDT_ACCESS_PRIVILEGE_RING_0 |
		GDT_ACCESS_CODE_DATA | GDT_ACCESS_READ_WRITE
} GDT_ACCESS;

typedef enum: u8 {
	// Use 4K page sizes for the limit. Otherwise use single byte
	GDT_FLAGS_GRANUALITY = 0b1000,

	// Is the segment 32-bit. Otherwise 16-bit
	GDT_FLAGS_SIZE = 0b0100,

	// Long mode (64-bit). If set, GDT_FLAGS_SIZE must be clear
	GDT_FLAGS_LONG = 0b0010

	// Last bit (0b0001) is reserved
} GDT_FLAGS;

typedef struct {
	u16 limit_low: 16;
	u16 base_low: 16;
	u8 base_middle: 8;
	u8 access: 8;
	u8 limit_high: 4;
	u8 flags: 4;
	u8 base_high: 4;
} __attribute__((packed)) gdt_entry;

typedef struct {
	u16 limit;
	gdt_entry* base_address;
} __attribute__((packed)) gdt_pointer;

void gdt_encode_entry(gdt_entry* entry, u32 base, u32 limit, GDT_ACCESS access, GDT_FLAGS flags) {
	SYSTEM_PANIC_IF(limit > 0xfffff, "GDT entry limit cannot be bigger than %x", 0xfffff);

	entry->base_low = base & 0xffff;
	entry->base_middle = (base >> 16) & 0xff;
	entry->base_high = (base >> 24) & 0xff;

	entry->limit_low = limit & 0xffff;
	entry->limit_high = (limit >> 16) & 0xf;

	entry->access = access;
	entry->flags = flags & 0xf;
}

extern void gdt_load(gdt_pointer* gdtptr);
