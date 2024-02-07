#include <stdint.h>
#include <stdio.h>

void kernel_main() {
	printf("Welcome, From Nilos!\n");
	printf("Unsigned: %u -- Negative: %i -- Hex: %x -- Octal: %o\n", UINT32_MAX, INT32_MIN, 139, 139);
}
