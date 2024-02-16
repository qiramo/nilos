CFLAGS += -m32

include $(ARCH_DIR)/x86/crt/Makefile

X86_OUT := $(OUT_DIR)/x86

X86_OBJS :=\
	boot.s.o\
	gdt.s.o\
	arch_init.c.o\
	tty.c.o

x86_arch: crt x86_out $(X86_OBJS)
	@ld -nostdlib -melf_i386 -T $(ARCH_DIR)/x86/linker.ld -o $(BUILD_DIR)/nilos_x86.elf\
		$(CRTI_OBJ) $(CRTBEGIN_OBJ)\
		$(wildcard $(LIBC_OUT)/*.o)\
		$(wildcard $(KERNEL_OUT)/*.o)\
		$(wildcard $(X86_OUT)/*.o)\
		$(CRTEND_OBJ) $(CRTN_OBJ)

$(filter %.s.o,$(X86_OBJS)): %.s.o: $(ARCH_DIR)/x86/%.s
	@$(CC) $(CFLAGS) -c $< -o $(X86_OUT)/$(notdir $@)

$(filter %.c.o,$(X86_OBJS)): %.c.o: $(ARCH_DIR)/x86/%.c
	@$(CC) $(CFLAGS) -c $< -o $(X86_OUT)/$(notdir $@)

x86_out:
	@mkdir -pv $(X86_OUT)
