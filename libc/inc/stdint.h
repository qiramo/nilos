#pragma once

typedef signed char int8_t;
typedef signed short int16_t;
typedef signed int int32_t;
typedef signed long long int64_t;

typedef unsigned char uint8_t;
typedef unsigned short uint16_t;
typedef unsigned int uint32_t;
typedef unsigned long long uint64_t;

typedef int8_t i8;
typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;

#define INT8_MAX (0x7F)
#define INT16_MAX (0x7FFF)
#define INT32_MAX (0x7FFFFFFF)
#define INT64_MAX (0x7FFFFFFFFFFFFFFF)

#define INT8_MIN (-INT8_MAX - 1)
#define INT16_MIN (-INT16_MAX -1)
#define INT32_MIN (-INT32_MAX - 1)
#define INT64_MIN (-INT64_MAX - 1)

#define UINT8_MAX (0xFF)
#define UINT16_MAX (0xFFFF)
#define UINT32_MAX (0xFFFFFFFF)
#define UINT64_MAX (0xFFFFFFFFFFFFFFFF)
