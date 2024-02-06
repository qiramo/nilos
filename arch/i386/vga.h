#include <stdint.h>

#include <kernel/tty.h>

#define VGA_WIDTH 80
#define VGA_HEIGHT 25
#define VGA_MEMORY (u16*)0xB8000

static inline u16 vga_entry(u8 c, u8 color) {
	return (u16)c | (u16)color << 8;
}

static inline u8 vga_entry_color(TTY_COLOR fg, TTY_COLOR bg) {
	return fg | bg << 4;
}
