#include <string.h>

i8 memcmp(const void* aptr, const void* bptr, u16 size) {
	const i8* restrict a = (i8*)aptr;
	const i8* restrict b = (i8*)bptr;

	for(u16 i = 0; i < size; i++) {
		if(a[i] < b[i]) {
			return -1;
		} else if(a[i] > b[i]) {
			return 1;
		}
	}

	return 0;
}

void* memcpy(void* dst, const void* src, u16 size) {
	i8* restrict a = (i8*)dst;
	const i8* restrict b = (i8*)src;

	for(u16 i = 0; i < size; i++) {
		a[i] = b[i];
	}

	return a;
}

void* memmove(void* dst, const void* src, u16 size) {
	i8* restrict a = (i8*)dst;
	const i8* restrict b = (i8*)src;

	if(dst > src) {
		for(u16 i = size; i != 0; i--) {
			a[i - 1] = b[i - 1];
		}
	} else {
		for(u16 i = 0; i < size; i++) {
			a[i] = b[i];
		}
	}

	return a;
}

void* memset(void* buf, i8 val, u16 size) {
	i8* ptr = (i8*)buf;

	for(u16 i = 0; i < size; i++) {
		ptr[i] = val;
	}

	return ptr;
}

u16 strlen(const char* str) {
	u16 len = 0;

	while(str[len]) {
		len++;
	}

	return len;
}
