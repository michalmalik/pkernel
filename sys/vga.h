#ifndef _SYS_VGA_H_
#define _SYS_VGA_H_

#include <sys/types.h>
#include <io.h>
#include <string.h>

#define VGA_MEMORY		0xB8000
#define VGA_WIDTH		80
#define VGA_HEIGHT		25

enum vga_color {
	COLOR_BLACK,
	COLOR_BLUE,
	COLOR_GREEN,
	COLOR_CYAN,
	COLOR_RED,
	COLOR_MAGENTA,
	COLOR_BROWN,
	COLOR_LIGHT_GREY,
	COLOR_DARK_GREY,
	COLOR_LIGHT_BLUE,
	COLOR_LIGHT_GREEN,
	COLOR_LIGHT_CYAN,
	COLOR_LIGHT_RED,
	COLOR_LIGHT_MAGENTA,
	COLOR_LIGHT_BROWN,
	COLOR_WHITE,
};

u8 make_color(enum vga_color fg, enum vga_color bg);
void vga_set_color(u8 color);
void vga_putchar(char c);
void vg_move_cursor();
void vga_clear();
void vga_write(const char *str);
void vga_write_hex(uint32_t n);
void vga_write_dec(uint32_t n);
void vga_init(u16 *vmem);

#endif