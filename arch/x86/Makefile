CFLAGS += -m32

X86_OBJS :=\
	boot.s.o\
	tty.c.o

x86_arch: $(X86_OBJS)
	@ld -nostdlib -melf_i386 -T $(ARCHDIR)/x86/linker.ld -o $(BUILDDIR)/nilos.elf $(wildcard $(OBJDIR)/*.o)

$(filter %.s.o,$(X86_OBJS)): %.s.o: $(ARCHDIR)/x86/%.s
	@$(CC) $(CFLAGS) -c $< -o $(OBJDIR)/$(@F:%.s.o=%.o)

$(filter %.c.o,$(X86_OBJS)): %.c.o: $(ARCHDIR)/x86/%.c
	@$(CC) $(CFLAGS) -c $< -o $(OBJDIR)/$(@F:%.c.o=%.o)
