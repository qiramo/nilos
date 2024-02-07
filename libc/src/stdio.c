#include <stdio.h>

#include <stdarg.h>
#include <stdint.h>
#include <stdlib.h>

#include <kernel/tty.h>

typedef enum: i8 {
	PRINTF_STATE_NORMAL,
	PRINTF_STATE_SPECIFIER
} PRINTF_STATE;

void putc(char c) {
	tty_put_char(c);
}

void puts(const char* str) {
	tty_write_string(str);
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
							char buf[32];
							u8 len = itoa(va_arg(args, i32), buf, 10);

							for(u8 i = 0; i < len; i++) {
								putc(buf[i]);
							}

							break;
						}

					case 'u':
						{
							char buf[32];
							u8 len = utoa(va_arg(args, u32), buf, 10);

							for(u8 i = 0; i < len; i++) {
								putc(buf[i]);
							}

							break;
						}

					case 'x':
						{
							char buf[32];
							u8 len = utoa(va_arg(args, u32), buf, 16);

							for(u8 i = 0; i < len; i++) {
								putc(buf[i]);
							}

							break;
						}

					case 'o':
						{
							char buf[32];
							u8 len = utoa(va_arg(args, u32), buf, 8);

							for(u8 i = 0; i < len; i++) {
								putc(buf[i]);
							}

							break;
						}

					default:
						break;
				}

				state = PRINTF_STATE_NORMAL;
		}

		fmt++;
	}

	va_end(args);
}
