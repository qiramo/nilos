#pragma once

#include <stdint.h>

typedef i32* va_list;

#define va_start(list, arg1) list = ((va_list)&arg1) + sizeof(arg1) / sizeof(i32)
#define va_arg(list, type) (*(type*)list++)
#define va_end(list) (list = 0)
