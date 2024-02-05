#include <stdint.h>
#include <string.h>

#include <kernel/tty.h>

#include "vga.h"

static const u16 VGA_WIDTH = 80;
static const u16 VGA_HEIGHT = 25;
static u16* const VGA_MEMORY = (u16*)0xB8000;

static u16 terminal_row;
static u16 terminal_column;
static u16 terminal_entry_index;

static u8 terminal_color;
static u16* terminal_buffer;

void terminal_initialize(TTY_COLOR fg, TTY_COLOR bg) {
	terminal_row = 0;
	terminal_column = 0;
	terminal_entry_index = 0;

	terminal_buffer = VGA_MEMORY;
	terminal_color = vga_entry_color(fg, bg);

	for(u16 y = 0; y < VGA_HEIGHT; y++) {
		const u16 yi = y * VGA_WIDTH;

		for(u16 x = 0; x < VGA_WIDTH; x++) {
			terminal_buffer[yi + x] = vga_entry(' ', terminal_color);
		}
	}
}

void terminal_set_font_color(TTY_COLOR col) {
	terminal_color = vga_entry_color(col, terminal_color << 4);
}

void terminal_new_line() {
	if(++terminal_row > VGA_HEIGHT) {
		terminal_row = 0;
	}

	terminal_column = 0;
	terminal_entry_index = terminal_row * VGA_WIDTH;
}

void terminal_put_char(char c) {
	if(c == '\n') {
		terminal_new_line();
		return;
	}

	terminal_buffer[terminal_entry_index++] = vga_entry(c, terminal_color);

	if(++terminal_column > VGA_WIDTH) {
		terminal_new_line();
	}
}

void terminal_write(const char* str, u16 size) {
	for(u16 i = 0; i < size; i++) {
		terminal_put_char(str[i]);
	}
}

void terminal_write_string(const char* str) {
	const u16 len = strlen(str);
	terminal_write(str, len);
	terminal_put_char('\n');
}
