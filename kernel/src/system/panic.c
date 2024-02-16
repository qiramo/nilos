#include <nilos/system/panic.h>

#include <nilos/system/logger.h>
#include <nilos/system/tty.h>

#define SYSTEM_HALT() asm volatile("hlt")

void system_panic(const char* file, u32 line, const char* msg, ...) {
	tty_initialize(TTY_COLOR_WHITE, TTY_COLOR_BLUE);

	system_log("Fatal System Error Occured!\n");
	system_log("File: %s\n", file);
	system_log("Line: %u\n", line);

	va_list args;
	va_start(args, msg);
	system_log_format(msg, args);
	va_end(args);

	while(1) {
		SYSTEM_HALT();
	}
}
