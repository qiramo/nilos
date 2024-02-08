#include <nilos/system/logger.h>

#include <stdarg.h>
#include <stdlib.h>

#include <nilos/system/tty.h>

typedef enum: i8 {
	LOG_STATE_NORMAL,
	LOG_STATE_SPECIFIER
} LOG_STATE;

static LOG_LEVEL log_level;

void system_set_log_level(LOG_LEVEL lvl) {
	if(lvl == log_level) {
		return;
	}

	switch(lvl) {
		case LOG_LEVEL_NORMAL:
			tty_set_font_color(TTY_COLOR_WHITE);
			break;

		case LOG_LEVEL_DEBUG:
			tty_set_font_color(TTY_COLOR_BLUE);
			break;

		case LOG_LEVEL_WARNING:
			tty_set_font_color(TTY_COLOR_BROWN);
			break;

		case LOG_LEVEL_ERROR:
			tty_set_font_color(TTY_COLOR_RED);
			break;

		default:
			break;
	}

	log_level = lvl;
}

static void system_log_format(const char* fmt, va_list args) {
	LOG_STATE state = LOG_STATE_NORMAL;

	char c;
	while((c = *fmt)) {
		switch (state) {
			case LOG_STATE_NORMAL:
				if(c == '%') {
					state = LOG_STATE_SPECIFIER;
				} else {
					tty_put_char(c);
				}
				break;

			case LOG_STATE_SPECIFIER:
				switch(c) {
					case '%':
						tty_put_char('%');
						break;

					case 'c':
						tty_put_char(va_arg(args, char));
						break;

					case 's':
						tty_write_string(va_arg(args, char*));
						break;

					case 'd':
					case 'i':
						{
							char buf[32];
							u8 len = itoa(va_arg(args, i32), buf, 10);

							for(u8 i = 0; i < len; i++) {
								tty_put_char(buf[i]);
							}

							break;
						}

					case 'u':
						{
							char buf[32];
							u8 len = utoa(va_arg(args, u32), buf, 10);

							for(u8 i = 0; i < len; i++) {
								tty_put_char(buf[i]);
							}

							break;
						}

					case 'x':
						{
							char buf[32];
							u8 len = utoa(va_arg(args, u32), buf, 16);

							for(u8 i = 0; i < len; i++) {
								tty_put_char(buf[i]);
							}

							break;
						}

					default:
						break;
				}

				state = LOG_STATE_NORMAL;
		}

		fmt++;
	}
}

void system_log(const char* fmt, ...) {
	va_list args;
	va_start(args, fmt);
	system_log_format(fmt, args);
	va_end(args);
}

void system_log_level(LOG_LEVEL lvl, const char* fmt, ...) {
	system_set_log_level(lvl);

	va_list args;
	va_start(args, fmt);
	system_log_format(fmt, args);
	va_end(args);
}
