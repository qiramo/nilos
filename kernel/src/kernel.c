#include <stdio.h>

#include <kernel/tty.h>

void kernel_main() {
	tty_initialize(TTY_COLOR_WHITE, TTY_COLOR_BLACK);
	printf("Welcome, From Nilos!\n");
	printf("Unsigned: %u -- Negative: %i -- Hex: %x -- Octal: %o\n", UINT32_MAX, INT32_MIN, 139, 139);
}
