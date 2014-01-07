#ifndef _SYS_STRING_H_
#define _SYS_STRING_H_

#include <sys/types.h>

void itoa(char *buf, uint32_t n, uint32_t base);

void *memset(void *d, char c, size_t n);
void *memcpy(void *d, void *s, size_t n);

void itoa(char *buf, uint32_t n, uint32_t base);

size_t strlen(const char *s);
int strcmp(const char *d, const char *s);
char *strcpy(char *d, const char *s);

#endif