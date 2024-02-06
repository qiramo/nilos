#include <stdio.h>

#include <stdarg.h>
#include <stdint.h>

#include <kernel/tty.h>

typedef enum: i8 {
	PRINTF_STATE_NORMAL,
	PRINTF_STATE_SPECIFIER
} PRINTF_STATE;

static const char* HEX_NUMBERS = "0123456789abcdef";

void putc(char c) {
	tty_put_char(c);
}

void puts(const char* str) {
	tty_write_string(str);
}

static void stdio_print_number(u32 num, i8 base) {
	i8 i = 0;
	char buf[32];
	u32 rem;

	do {
		rem = num % base;
		num -= rem;
		num /= base;
		buf[i++] = HEX_NUMBERS[rem];
	} while(num > 0);

	while(i--) {
		putc(buf[i]);
	}
}

void printf(const char* fmt, ...) {
	va_list args;
	va_start(args, fmt);

	PRINTF_STATE state = PRINTF_STATE_NORMAL;

	char c;
	while((c = *fmt)) {
		switch (state) {
			case PRINTF_STATE_NORMAL:
				if(c == '%') {
					state = PRINTF_STATE_SPECIFIER;
				} else {
					putc(c);
				}
				break;

			case PRINTF_STATE_SPECIFIER:
				switch(c) {
					case '%':
						putc('%');
						break;

					case 'c':
						putc(va_arg(args, char));
						break;

					case 's':
						puts(va_arg(args, char*));
						break;

					case 'd':
					case 'i':
						{
							const i32 org = va_arg(args, i32);
							u32 num;

							if(org < 0) {
								putc('-');
								num = -org;
							} else {
								num = org;
							}

							stdio_print_number(num, 10);
							break;
						}

					case 'u':
						stdio_print_number(va_arg(args, u32), 10);
						break;

					case 'x':
						stdio_print_number(va_arg(args, u32), 16);
						break;

					case 'o':
						stdio_print_number(va_arg(args, u32), 8);
						break;

					default:
						break;
				}

				state = PRINTF_STATE_NORMAL;
		}

		fmt++;
	}

	va_end(args);
}
