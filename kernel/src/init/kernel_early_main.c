#include <nilos/tty.h>

void kernel_early_main() {
	tty_initialize(TTY_COLOR_WHITE, TTY_COLOR_BLACK);
}
