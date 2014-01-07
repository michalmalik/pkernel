#include <io.h>

void outb(u32 p, u8 v)
{
	asmv("outb %%al, %%dx" :: "d"(p), "a"(v));
}

void outw(u32 p, u16 v)
{
	asmv("outw %%ax, %%dx" :: "d"(p), "a"(v));
}

void outl(u32 p, u32 v)
{
	asmv("outl %%eax, %%dx" :: "d"(p), "a"(v));
}

u8 inb(u32 p)
{
	u8 _v;
	asmv("inb %%dx, %%al" : "=a"(_v) : "d"(p));
	return _v;
}

u16 inw(u32 p)
{
	u16 _v;
	asmv("inw %%dx, %%ax" : "=a"(_v) : "d"(p));
	return _v;
}

u32 inl(u32 p)
{
	u32 _v;
	asmv("inl %%dx, %%eax" : "=a"(_v) : "d"(p));
	return _v;
}

// Enable hardware interrupts
void cli()
{
	asmv("cli");
}

// Enable interrupts
void sti()
{
	asmv("sti");
}