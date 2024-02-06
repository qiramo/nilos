#include <stdint.h>
#include <string.h>

#include <kernel/tty.h>

#include "vga.h"

static const u16 VGA_WIDTH = 80;
static const u16 VGA_HEIGHT = 25;
static u16* const VGA_MEMORY = (u16*)0xB8000;

static u16 tty_row;
static u16 tty_column;
static u16 tty_entry_index;

static u8 tty_color;
static u16* tty_buffer;

void tty_initialize(TTY_COLOR fg, TTY_COLOR bg) {
	tty_row = 0;
	tty_column = 0;
	tty_entry_index = 0;

	tty_buffer = VGA_MEMORY;
	tty_color = vga_entry_color(fg, bg);

	for(u16 y = 0; y < VGA_HEIGHT; y++) {
		const u16 yi = y * VGA_WIDTH;

		for(u16 x = 0; x < VGA_WIDTH; x++) {
			tty_buffer[yi + x] = vga_entry(' ', tty_color);
		}
	}
}

void tty_set_font_color(TTY_COLOR col) {
	tty_color = vga_entry_color(col, tty_color << 4);
}

void tty_new_line() {
	if(tty_row >= VGA_HEIGHT - 1) {
		tty_row = 0;
	} else {
		tty_row++;
	}

	tty_column = 0;
	tty_entry_index = tty_row * VGA_WIDTH;
}

void tty_put_char(char c) {
	if(c == '\n') {
		tty_new_line();
		return;
	}

	tty_buffer[tty_entry_index++] = vga_entry(c, tty_color);

	if(tty_column >= VGA_WIDTH - 1) {
		tty_new_line();
	} else {
		tty_column++;
	}
}

void tty_write(const char* str, u16 size) {
	for(u16 i = 0; i < size; i++) {
		tty_put_char(str[i]);
	}
}

void tty_write_string(const char* str) {
	const u16 len = strlen(str);
	tty_write(str, len);
}
