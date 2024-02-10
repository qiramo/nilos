CFLAGS += -m32

X86_SRCS :=\
	boot.s\
	tty.c

X86_SRCS := $(addprefix $(ARCHDIR)/x86/,$(X86_SRCS))
X86_OBJS := $(X86_SRCS:%=%.o)

x86_arch: $(X86_OBJS)
	@ld -nostdlib -melf_i386 -T $(ARCHDIR)/x86/linker.ld -o $(BUILDDIR)/nilos.elf $(wildcard $(OBJDIR)/*)

%.s.o: %.s
	@$(CC) $(CFLAGS) -c $< -o $(OBJDIR)/$(@F)

%.c.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $(OBJDIR)/$(@F)
