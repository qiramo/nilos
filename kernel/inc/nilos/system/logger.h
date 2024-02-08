#pragma once

#include <stdint.h>

typedef enum: i8 {
	LOG_LEVEL_NORMAL,
	LOG_LEVEL_TRACE,
	LOG_LEVEL_DEBUG,
	LOG_LEVEL_WARNING,
	LOG_LEVEL_ERROR
} LOG_LEVEL;

void system_set_log_level(LOG_LEVEL lvl);

void system_log(const char* fmt, ...);
void system_log_level(LOG_LEVEL lvl, const char* fmt, ...);

#define SYSTEM_LOG_NORMAL(fmt, ...) system_log_level(LOG_LEVEL_NORMAL, fmt, ##__VA_ARGS__)
#define SYSTEM_LOG_TRACE(fmt, ...) system_log_level(LOG_LEVEL_TRACE, fmt, ##__VA_ARGS__)
#define SYSTEM_LOG_DEBUG(fmt, ...) system_log_level(LOG_LEVEL_DEBUG, fmt, ##__VA_ARGS__)
#define SYSTEM_LOG_WARNING(fmt, ...) system_log_level(LOG_LEVEL_WARNING, fmt, ##__VA_ARGS__)
#define SYSTEM_LOG_ERROR(fmt, ...) system_log_level(LOG_LEVEL_ERROR, fmt, ##__VA_ARGS__)
