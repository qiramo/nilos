KERNEL_SRCS :=\
	init/kernel_early_main.c\
	init/kernel_main.c\
	system/logger.c\
	system/panic.c

KERNEL_SRCS := $(addprefix $(KERNELDIR)/src/,$(KERNEL_SRCS))
KERNEL_OBJS := $(KERNEL_SRCS:%=%.o)

kernel: $(KERNEL_OBJS)

%.c.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $(OBJDIR)/$(@F)
