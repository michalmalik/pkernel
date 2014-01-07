#ifndef _SYS_TYPES_H_
#define _SYS_TYPES_H_

#include <stddef.h>
#include <stdint.h>

typedef uint8_t		u8;
typedef uint16_t	u16;
typedef uint32_t	u32;
typedef int8_t		s8;
typedef int16_t 	s16;
typedef int32_t		s32;

#define asm 		__asm__
#define asmv		__asm__ volatile

#define false		0
#define true		1

#endif