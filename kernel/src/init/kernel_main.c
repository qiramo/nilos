#include <nilos/system/logger.h>

void kernel_main() {
	SYSTEM_LOG_NORMAL("Welcome, From Nilos!\n");
	SYSTEM_LOG_NORMAL("Unsigned: %u -- Negative: %i -- Hex: %x\n", UINT32_MAX, INT32_MIN, 139);
}
