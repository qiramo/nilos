KERNEL_OBJS :=\
	init/kernel_early_main.c.o\
	init/kernel_main.c.o\
	system/logger.c.o\
	system/panic.c.o

kernel: $(KERNEL_OBJS)

$(filter %.c.o,$(KERNEL_OBJS)): %.c.o: $(KERNELDIR)/src/%.c
	@$(CC) $(CFLAGS) -c $< -o $(OBJDIR)/$(@F:%.c.o=%.o)
