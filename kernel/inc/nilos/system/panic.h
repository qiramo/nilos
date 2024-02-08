#pragma once

#include <stdint.h>

void system_panic(const char* msg, const char* file, u32 line);

#define SYSTEM_PANIC_IF(expr, msg) (!(expr))? 0 : system_panic(msg, __FILE__, __LINE__)
#define SYSTEM_PANIC_IFN(expr, msg) ((expr))? 0 : system_panic(msg, __FILE__, __LINE__)
