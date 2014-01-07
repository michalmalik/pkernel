#include <vga.h>
#include <desc_tables.h>
#include <int.h>

isr_ptr interrupt_handlers[256];

void isr_handler(struct registers regs)
{
	if(interrupt_handlers[regs.int_no] != 0) {
		isr_ptr handler = interrupt_handlers[regs.int_no];
		handler(regs);
	} else {
		vga_write("unhandled interrupt: ");
		vga_write_dec(regs.int_no);
		vga_putchar('\n');
	}
}

void register_interrupt_handler(u8 n, isr_ptr handler)
{
	interrupt_handlers[n] = handler;
}

void irq_handler(struct registers regs)
{
	if(regs.int_no >= 0x28) {
		outb(PIC2_IRQ_COMMAND, PIC_EOI);
	}

	outb(PIC1_IRQ_COMMAND, PIC_EOI);

	if(interrupt_handlers[regs.int_no] != 0) {
		isr_ptr handler = interrupt_handlers[regs.int_no];
		handler(regs);
	}
}