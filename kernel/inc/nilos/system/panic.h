#pragma once

#include <stdint.h>

void system_panic(const char* file, u32 line, const char* msg, ...);

#define SYSTEM_PANIC_IF(expr, msg, ...) (!(expr))? 0 : system_panic(__FILE__, __LINE__, msg, ##__VA_ARGS__)
#define SYSTEM_PANIC_IFN(expr, msg, ...) ((expr))? 0 : system_panic(__FILE__, __LINE__, msg, ##__VA_ARGS__)
