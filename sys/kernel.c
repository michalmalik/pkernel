#include <desc_tables.h>
#include <sys/vga.h>

void kmain()
{
	init_descriptor_tables();
	vga_init((u16 *)VGA_MEMORY);
	
	vga_write("Hello Kernel World!\n");
}