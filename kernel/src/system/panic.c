#include <nilos/system/panic.h>

#include <nilos/system/logger.h>
#include <nilos/system/tty.h>

#define SYSTEM_IRQ_OFF() asm volatile("cli")
#define SYSTEM_HALT() asm volatile("hlt")

void system_panic(const char* msg, const char* file, u32 line) {
	tty_initialize(TTY_COLOR_WHITE, TTY_COLOR_BLUE);

	system_log("Fatal System Error Occured!\n");
	system_log("Info: %s\n", msg);
	system_log("File: %s\n", file);
	system_log("Line: %u\n", line);

	while(1) {
		SYSTEM_IRQ_OFF();
		SYSTEM_HALT();
	}
}
