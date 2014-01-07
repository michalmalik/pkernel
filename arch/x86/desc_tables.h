#ifndef _ARCH_DESC_TABLES_H_
#define _ARCH_DESC_TABLES_H_

#include <sys/types.h>
#include <sys/string.h>
#include <io.h>

#define PIC1_IRQ_COMMAND	0x20
#define PIC1_IRQ_DATA		0x21
#define PIC2_IRQ_COMMAND	0xA0
#define PIC2_IRQ_DATA		0xA1
#define PIC_EOI			0x20

#define KERNEL_CS		0x08	// code segment	
#define KERNEL_DS		0x10	// data segment

/*
	=== Flags

	+---+---+---+---+---+---+---+---+
	| p |  dpl  | s |     flags     |
	+---+---+---+---+---+---+---+---+
*/
struct idt_entry {
	u16 base_lo;
	u16 sel;
	u8 zero;
	u8 flags;
	u16 base_hi;
} __attribute__((packed));

struct idt_ptr {
	u16 limit;
	u32 base;
} __attribute__((packed));

struct gdt_entry {
	u16 limit_lo;
	u16 base_lo;
	u8 base_mi;
	u8 dpl;
	u8 gran;
	u8 base_hi;
} __attribute__((packed));

struct gdt_ptr {
	u16 limit;
	u32 base;
} __attribute__((packed));

extern void gdt_flush(uint32_t);
extern void idt_flush(uint32_t);

void init_descriptor_tables();

extern void isr0();
extern void isr1();
extern void isr2();
extern void isr3();
extern void isr4();
extern void isr5();
extern void isr6();
extern void isr7();
extern void isr8();
extern void isr9();
extern void isr10();
extern void isr11();
extern void isr12();
extern void isr13();
extern void isr14();
extern void isr15();
extern void isr16();
extern void isr17();
extern void isr18();
extern void isr19();
extern void isr20();
extern void isr21();
extern void isr22();
extern void isr23();
extern void isr24();
extern void isr25();
extern void isr26();
extern void isr27();
extern void isr28();
extern void isr29();
extern void isr30();
extern void isr31();

extern void irq0();
extern void irq1();
extern void irq2();
extern void irq3();
extern void irq4();
extern void irq5();
extern void irq6();
extern void irq7();
extern void irq8();
extern void irq9();
extern void irq10();
extern void irq11();
extern void irq12();
extern void irq13();
extern void irq14();
extern void irq15();

#endif