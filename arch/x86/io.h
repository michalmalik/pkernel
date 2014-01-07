#ifndef _ARCH_IO_H_
#define _ARCH_IO_H_

#include <sys/types.h>

void outb(u32 p, u8 v);
void outw(u32 p, u16 v);
void outl(u32 p, u32 v);

u8 inb(u32 p);
u16 inw(u32 p);
u32 inl(u32 p);

void cli();
void sti();

#endif