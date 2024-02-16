#include <nilos/system/tty.h>

extern void arch_init();

void kernel_early_main() {
	arch_init();
	tty_initialize(TTY_COLOR_WHITE, TTY_COLOR_BLACK);
}
