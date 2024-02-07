#include <stdlib.h>

#include <stdbool.h>

static const u8 BUFFER_SIZE = 32;
static const char* HEX_NUMBERS = "0123456789abcdef";

u8 itoa(i32 num, char* str, u8 base) {
	const bool neg = num < 0;
	u32 number = neg? -num : num;

	u8 len = 0;
	char buf[BUFFER_SIZE];

	if(neg) {
		str[0] = '-';
	}

	do {
		buf[len++] = HEX_NUMBERS[number % base];
		number /= base;
	} while(number > 0);

	for(u8 i = 0; i < len; i++) {
		str[i + neg] = buf[(len - i) - 1];
	}

	str[len + neg] = '\0';
	return len + neg;
}

u8 utoa(u32 num, char* str, u8 base) {
	u8 len = 0;
	char buf[BUFFER_SIZE];

	do {
		buf[len++] = HEX_NUMBERS[num % base];
		num /= base;
	} while(num > 0);

	for(u8 i = 0; i < len; i++) {
		str[i] = buf[(len - i) - 1];
	}

	str[len] = '\0';
	return len;
}
