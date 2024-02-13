KERNEL_OUT := $(OUT_DIR)/kernel

KERNEL_OBJS :=\
	init/kernel_early_main.c.o\
	init/kernel_main.c.o\
	system/logger.c.o\
	system/panic.c.o

kernel: kernel_out $(KERNEL_OBJS)

$(filter %.c.o,$(KERNEL_OBJS)): %.c.o: $(KERNEL_DIR)/src/%.c
	@$(CC) $(CFLAGS) -c $< -o $(KERNEL_OUT)/$(notdir $@)

kernel_out:
	@mkdir -pv $(KERNEL_OUT)
