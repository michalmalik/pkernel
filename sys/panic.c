#include <types.h>
#include <io.h>
#include <vga.h>
#include <assert.h>

static inline void __hlt()
{
	for(;;);
}

void panic(const char *msg, const char *file, u32 line)
{
	vga_write("[KERNEL PANIC] ");
	vga_write(file);
	vga_putchar(':');
	vga_write_dec(line);
	vga_write(": ");
	vga_write(msg);
	__hlt();
}

void panic_assert(const char *file, u32 line, const char *desc)
{
	vga_write("[KERNEL] assertion ");
	vga_write(desc);
	vga_write(" failed");
	vga_write(" : ");
	vga_write(file);
	vga_putchar(':');
	vga_write_dec(line);
	__hlt();
}