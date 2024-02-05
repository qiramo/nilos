#include <kernel/tty.h>

void kernel_main() {
	terminal_initialize(TTY_COLOR_WHITE, TTY_COLOR_BLACK);
	terminal_write_string("Welcome, From Nilos!");
}
