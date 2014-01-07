MBALIGN     equ  	1<<0                   
MEMINFO     equ  	1<<1                   
FLAGS       equ  	MBALIGN|MEMINFO      
MAGIC       equ  	0x1BADB002            
CHECKSUM    equ 	-(MAGIC+FLAGS)        
 
section .multiboot
align 4
	dd MAGIC
	dd FLAGS
	dd CHECKSUM
 
section .bootstrap_stack
align 4
	stack_bottom:
		times 16384 db 0
	stack_top:
 
section .text
	global _start
	_start:
		mov esp, stack_top
		cli

	 	extern kmain
		call kmain
	.hang:
		hlt
		jmp .hang

global idt_flush
idt_flush:
	mov eax, [esp+4]
	lidt [eax]
	ret

global gdt_flush
gdt_flush:
	mov eax, [esp+4]
	lgdt [eax]
	ret