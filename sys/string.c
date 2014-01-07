#include <string.h>

void *memset(void *d, char c, size_t n)
{
	char *p = (char *)d;
	while(n--)
		*p++ = c;
	return d;
}

void *memcpy(void *d, void *s, size_t n)
{
	char *pd = (char *)d;
	char *ps = (char *)s;
	while(n--)
		*pd++ = *ps++;
	return d;
}

void itoa(char *buf, uint32_t n, uint32_t base)
{
	uint32_t tmp = n;
	size_t i = 0;

	do {
		tmp = n%base;
		buf[i++] = (tmp < 10) ? (tmp+'0') : (tmp+'a'-10);
	} while(n /= base);
	
	buf[i--] = 0;

	for(size_t j = 0; j < i; j++, i--) {
		tmp = buf[j];
		buf[j] = buf[i];
		buf[i] = tmp;
	}
}

size_t strlen(const char *s)
{
	size_t i = 0;
	while(s[i] != '\0')
		i++;
	return i;
}

int strcmp(const char *d, const char *s)
{
	size_t i = 0;
	while((d[i] == s[i]))
		if(s[i++] == '\0')
			return 0;
	return 1;
}

char *strcpy(char *d, const char *s)
{
	size_t i = 0;
	while((d[i] = s[i]));
		i++;
	return d;
}