#include <desc_tables.h>

struct gdt_entry gdt[5];
struct gdt_ptr gdtp;

struct idt_entry idt[256];
struct idt_ptr idtp;

static void init_gdt();
static void init_idt();

static void gdt_set_gate(s32, u32, u32, u8, u8);
static void idt_set_gate(u8, u32, u16, u8);

void init_descriptor_tables()
{
	init_gdt();
	init_idt();
	sti();
}

static void init_gdt()
{
	gdtp.limit = sizeof(struct gdt_entry)*5-1;
	gdtp.base = (u32)&gdt;

	gdt_set_gate(0, 0, 0, 0, 0);			// null segment
	gdt_set_gate(1, 0, 0xffffffff, 0x9a, 0xcf);	// code segment
	gdt_set_gate(2, 0, 0xffffffff, 0x92, 0xcf);	// data segment
	gdt_set_gate(3, 0, 0xffffffff, 0xfa, 0xcf);	// user code
	gdt_set_gate(4, 0, 0xffffffff, 0xf2, 0xcf);	// user data

	gdt_flush((u32)&gdtp);
}

static void gdt_set_gate(s32 n, u32 base, u32 limit, u8 acc, u8 gran)
{
	struct gdt_entry gdte = {
		.limit_lo = (u16)(limit&0xffff),
		.base_lo = (u16)(base&0xffff),
		.base_mi = (u8)((base>>24)&0xff),
		.dpl = acc,
		.gran = ((limit>>16)&0xf)|(gran&0xf0),
		.base_hi = (base>>24)&0xff
	};

	gdt[n] = gdte;
}

static void init_idt()
{
	idtp.limit = sizeof(struct idt_entry)*256-1;
	idtp.base = (u32)&idt;

	memset(&idt, 0, sizeof(struct idt_entry)*256);

	idt_set_gate(0, (u32)isr0, KERNEL_CS, 0x8E);
	idt_set_gate(1, (u32)isr1, KERNEL_CS, 0x8E);
	idt_set_gate(2, (u32)isr2, KERNEL_CS, 0x8E);
	idt_set_gate(3, (u32)isr3, KERNEL_CS, 0x8E);
	idt_set_gate(4, (u32)isr4, KERNEL_CS, 0x8E);
	idt_set_gate(5, (u32)isr5, KERNEL_CS, 0x8E);
	idt_set_gate(6, (u32)isr6, KERNEL_CS, 0x8E);
	idt_set_gate(7, (u32)isr7, KERNEL_CS, 0x8E);
	idt_set_gate(8, (u32)isr8, KERNEL_CS, 0x8E);
	idt_set_gate(9, (u32)isr9, KERNEL_CS, 0x8E);
	idt_set_gate(10, (u32)isr10, KERNEL_CS, 0x8E);
	idt_set_gate(11, (u32)isr11, KERNEL_CS, 0x8E);
	idt_set_gate(12, (u32)isr12, KERNEL_CS, 0x8E);
	idt_set_gate(13, (u32)isr13, KERNEL_CS, 0x8E);
	idt_set_gate(14, (u32)isr14, KERNEL_CS, 0x8E);
	idt_set_gate(15, (u32)isr15, KERNEL_CS, 0x8E);
	idt_set_gate(16, (u32)isr16, KERNEL_CS, 0x8E);
	idt_set_gate(17, (u32)isr17, KERNEL_CS, 0x8E);
	idt_set_gate(18, (u32)isr18, KERNEL_CS, 0x8E);
	idt_set_gate(19, (u32)isr19, KERNEL_CS, 0x8E);
	idt_set_gate(20, (u32)isr20, KERNEL_CS, 0x8E);
	idt_set_gate(21, (u32)isr21, KERNEL_CS, 0x8E);
	idt_set_gate(22, (u32)isr22, KERNEL_CS, 0x8E);
	idt_set_gate(23, (u32)isr23, KERNEL_CS, 0x8E);
	idt_set_gate(24, (u32)isr24, KERNEL_CS, 0x8E);
	idt_set_gate(25, (u32)isr25, KERNEL_CS, 0x8E);
	idt_set_gate(26, (u32)isr26, KERNEL_CS, 0x8E);
	idt_set_gate(27, (u32)isr27, KERNEL_CS, 0x8E);
	idt_set_gate(28, (u32)isr28, KERNEL_CS, 0x8E);
	idt_set_gate(29, (u32)isr29, KERNEL_CS, 0x8E);
	idt_set_gate(30, (u32)isr30, KERNEL_CS, 0x8E);
	idt_set_gate(31, (u32)isr31, KERNEL_CS, 0x8E);

	outb(PIC1_IRQ_COMMAND, 0x11);
	outb(PIC2_IRQ_COMMAND, 0x11);
	outb(PIC1_IRQ_DATA, 0x20);
	outb(PIC2_IRQ_DATA, 0x28);
	outb(PIC1_IRQ_DATA, 0x04);
	outb(PIC2_IRQ_DATA, 0x02);
	outb(PIC1_IRQ_DATA, 0x01);
	outb(PIC2_IRQ_DATA, 0x01);
	outb(PIC1_IRQ_DATA, 0x0);
	outb(PIC2_IRQ_DATA, 0x0);

	idt_set_gate(0x20, (u32)irq0, KERNEL_CS, 0x8E);
	idt_set_gate(0x21, (u32)irq1, KERNEL_CS, 0x8E);
	idt_set_gate(0x22, (u32)irq2, KERNEL_CS, 0x8E);
	idt_set_gate(0x23, (u32)irq3, KERNEL_CS, 0x8E);
	idt_set_gate(0x24, (u32)irq4, KERNEL_CS, 0x8E);
	idt_set_gate(0x25, (u32)irq5, KERNEL_CS, 0x8E);
	idt_set_gate(0x26, (u32)irq6, KERNEL_CS, 0x8E);
	idt_set_gate(0x27, (u32)irq7, KERNEL_CS, 0x8E);
	idt_set_gate(0x28, (u32)irq8, KERNEL_CS, 0x8E);
	idt_set_gate(0x29, (u32)irq9, KERNEL_CS, 0x8E);
	idt_set_gate(0x2A, (u32)irq10, KERNEL_CS, 0x8E);
	idt_set_gate(0x2B, (u32)irq11, KERNEL_CS, 0x8E);
	idt_set_gate(0x2C, (u32)irq12, KERNEL_CS, 0x8E);
	idt_set_gate(0x2D, (u32)irq13, KERNEL_CS, 0x8E);
	idt_set_gate(0x2E, (u32)irq14, KERNEL_CS, 0x8E);
	idt_set_gate(0x2F, (u32)irq15, KERNEL_CS, 0x8E);

	idt_flush((u32)&idtp);
}

static void idt_set_gate(u8 n, u32 base, u16 sel, u8 flags)
{
	struct idt_entry idte = {
		.base_lo = (u16)(base&0xffff),
		.sel = sel,
		.zero = 0,
		.flags = flags,
		.base_hi = (u16)((base>>16)&0xffff)
	};

	idt[n] = idte;
}