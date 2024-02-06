#include <string.h>

i8 memcmp(const void* aptr, const void* bptr, u16 size) {
	const i8* restrict a = (i8*)aptr;
	const i8* restrict b = (i8*)bptr;

	while(size--) {
		if(a[size] < b[size]) {
			return -1;
		} else if(a[size] > b[size]) {
			return 1;
		}
	}

	return 0;
}

void* memcpy(void* dst, const void* src, u16 size) {
	i8* restrict a = (i8*)dst;
	const i8* restrict b = (i8*)src;

	while(size--) {
		a[size] = b[size];
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

i8 strcmp(const char* aptr, const char* bptr) {
	u16 i = 0;

	while(aptr[i] && bptr[i]) {
		if(aptr[i] < bptr[i]) {
			return -1;
		} else if(aptr[i] > bptr[i]) {
			return 1;
		}

		i++;
	}

	return 0;
}

char* strcpy(char* dst, const char* src) {
	u16 i = 0;

	while(dst[i]) {
		dst[i] = src[i];
		i++;
	}

	return dst;
}
