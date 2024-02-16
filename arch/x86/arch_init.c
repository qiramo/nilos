#include "gdt.h"

void arch_init() {
	gdt_entry gdt[3];

	// Null segment
	gdt_encode_entry(&gdt[0], 0, 0, 0, 0);

	// Kernel code segment
	const GDT_ACCESS kernel_code_segment_access = GDT_ACCESS_KERNEL_CODE;
	const GDT_FLAGS kernel_code_segment_flags = GDT_FLAGS_SIZE | GDT_FLAGS_GRANUALITY;
	gdt_encode_entry(&gdt[1], 0, 0xfffff, kernel_code_segment_access, kernel_code_segment_flags);

	// Kernel data segment
	const GDT_ACCESS kernel_data_segment_access = GDT_ACCESS_KERNEL_DATA;
	const GDT_FLAGS kernel_data_segment_flags = GDT_FLAGS_SIZE | GDT_FLAGS_GRANUALITY;
	gdt_encode_entry(&gdt[2], 0, 0xfffff, kernel_data_segment_access, kernel_data_segment_flags);

	gdt_pointer gdtptr;
	gdtptr.limit = sizeof(gdt_entry) * 3 - 1;
	gdtptr.base_address = &gdt[0];

	gdt_load(&gdtptr);
}
