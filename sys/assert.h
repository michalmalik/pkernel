#ifndef _SYS_ASSERT_H_
#define _SYS_ASSERT_H_

#include <types.h>

#define PANIC(msg) panic(msg, __FILE__, __LINE__)
#define ASSERT(b) (!(b) ? panic_assert(__FILE__, __LINE__, #b) : (void) 0)

extern void panic(const char *msg, const char *file, u32 line);
extern void panic_assert(const char *file, u32 line, const char *desc);

#endif