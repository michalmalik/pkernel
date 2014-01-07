ARCH=x86
KERNEL=kernel.bin
DBGKERNEL=kernel.sym
INC_DIR= -I ./ -I ./sys -I ./arch/$(ARCH)

include ./arch/$(ARCH)/config.make
include ./sys/Makefile
include ./arch/$(ARCH)/Makefile

all: $(KERNEL)

$(KERNEL): $(OBJS)
	$(CC) $(LFLAGS) -o $(KERNEL) $^
	$(OBJC) --only-keep-debug $(KERNEL) $(DBGKERNEL)
	$(OBJC) --strip-debug $(KERNEL)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

%.o: %.asm
	$(ASM) $(ASMFLAGS) $< -o $@

clean:
	rm $(OBJS) $(KERNEL) $(DBGKERNEL)

run:
	$(QEMU) -kernel $(KERNEL) -monitor stdio

debug:
	$(QEMU) -s -S -kernel $(KERNEL) -monitor stdio