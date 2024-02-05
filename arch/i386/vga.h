#include <stdint.h>

#include <kernel/tty.h>

static inline u8 vga_entry_color(TTY_COLOR fg, TTY_COLOR bg) {
	return fg | bg << 4;
}

static inline u16 vga_entry(u8 c, u8 color) {
	return (u16)c | (u16)color << 8;
}
