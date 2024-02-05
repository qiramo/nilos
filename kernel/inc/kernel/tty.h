#pragma once

#include <stdint.h>

typedef enum: i8 {
	TTY_COLOR_BLACK = 0,
	TTY_COLOR_BLUE = 1,
	TTY_COLOR_GREEN = 2,
	TTY_COLOR_CYAN = 3,
	TTY_COLOR_RED = 4,
	TTY_COLOR_MAGENTA = 5,
	TTY_COLOR_BROWN = 6,
	TTY_COLOR_LIGHT_GREY = 7,
	TTY_COLOR_DARK_GREY = 8,
	TTY_COLOR_LIGHT_BLUE = 9,
	TTY_COLOR_LIGHT_GREEN = 10,
	TTY_COLOR_LIGHT_CYAN = 11,
	TTY_COLOR_LIGHT_RED = 12,
	TTY_COLOR_LIGHT_MAGENTA = 13,
	TTY_COLOR_LIGHT_BROWN = 14,
	TTY_COLOR_WHITE = 15
} TTY_COLOR;

void terminal_initialize(TTY_COLOR fg, TTY_COLOR bg);
void terminal_set_font_color(TTY_COLOR col);

void terminal_new_line();
void terminal_put_char(char c);
void terminal_write(const char* str, u16 size);
void terminal_write_string(const char* str);
