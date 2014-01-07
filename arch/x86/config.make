CC = /home/michal/opt/gcc-4.8.2/bin/i686-pc-linux-gnu-gcc
CFLAGS = $(INC_DIR) -ffreestanding -O2 -Wall -Wextra -pedantic -fno-exceptions -std=gnu99 -g
LFLAGS = -T arch/$(ARCH)/linker.ld -ffreestanding -O2 -nostdlib -lgcc
ASM = nasm
ASMFLAGS = -f elf
QEMU = qemu-system-i386
OBJC = objcopy