#include <stdint.h>

i8 memcmp(const void* aptr, const void* bptr, u16 size);
void* memcpy(void* dst, const void* src, u16 size);
void* memmove(void* dst, const void* src, u16 size);
void* memset(void* buf, i8 val, u16 size);

u16 strlen(const char* str);
