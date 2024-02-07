#include <kernel/tty.h>

#include <stdbool.h>
#include <stdint.h>
#include <string.h>

#include "vga.h"

static u8 tty_row;
static u8 tty_column;
static u16 tty_entry_index;

static u16 tty_empty;
static bool tty_add_new_line;
static u8 tty_buffer_chars[VGA_HEIGHT];

static u8 tty_color;
static u16* tty_buffer;

void tty_initialize(TTY_COLOR fg, TTY_COLOR bg) {
	tty_row = 0;
	tty_column = 0;
	tty_entry_index = 0;

	tty_empty = vga_entry(' ', tty_color);
	tty_add_new_line = false;

	tty_color = vga_entry_color(fg, bg);
	tty_buffer = VGA_MEMORY;

	for(u8 y = 0; y < VGA_HEIGHT; y++) {
		tty_buffer_chars[y] = 0;

		const u16 yi = y * VGA_WIDTH;
		for(u8 x = 0; x < VGA_WIDTH; x++) {
			tty_buffer[yi + x] = tty_empty;
		}
	}
}

void tty_set_font_color(TTY_COLOR col) {
	tty_color = vga_entry_color(col, tty_color << 4);
}

static u8 tty_scroll(u8 lines) {
	u8 prev_y = 0;
	for(u8 y = lines; y < VGA_HEIGHT; y++) {
		const u8 chars = tty_buffer_chars[y];
		const u8 prev_chars = tty_buffer_chars[prev_y];

		const u16 yi = y * VGA_WIDTH;
		const u16 prev_yi = prev_y * VGA_WIDTH;

		for(u16 x = 0; x < chars; x++) {
			tty_buffer[prev_yi + x] = tty_buffer[yi + x];
		}

		for(i8 diff = chars; diff < prev_chars; diff++) {
			tty_buffer[prev_yi + diff] = tty_empty;
		}

		tty_buffer_chars[prev_y++] = chars;
	}

	for(u8 y = VGA_HEIGHT - 1; y > (VGA_HEIGHT - lines) - 1; y--) {
		const u8 chars = tty_buffer_chars[y];
		const u16 yi = y * VGA_WIDTH;

		for(u16 x = 0; x < chars; x++) {
			tty_buffer[yi + x] = tty_empty;
		}

		tty_buffer_chars[y] = 0;
	}

	return lines;
}

void tty_new_line() {
	tty_row++;
	if(tty_row > VGA_HEIGHT - 1) {
		tty_row -= tty_scroll(1);
	}

	tty_column = 0;
	tty_entry_index = tty_row * VGA_WIDTH;
	tty_add_new_line = false;
}

void tty_put_char(char c) {
	if(tty_add_new_line) {
		tty_new_line();
	}

	switch(c) {
		case '\n':
			tty_add_new_line = true;
			tty_buffer_chars[tty_row] = tty_column;
			return;
	}

	tty_buffer[tty_entry_index++] = vga_entry(c, tty_color);
	tty_column++;

	if(tty_column > VGA_WIDTH - 1) {
		tty_add_new_line = true;
		tty_buffer_chars[tty_row] = tty_column;
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
