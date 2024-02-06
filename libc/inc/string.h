#pragma once

#include <stdint.h>

i8 memcmp(const void* aptr, const void* bptr, u16 size);
void* memcpy(void* dst, const void* src, u16 size);
void* memset(void* buf, i8 val, u16 size);

u16 strlen(const char* str);
i8 strcmp(const char* aptr, const char* bptr);
char* strcpy(char* dst, const char* src);
