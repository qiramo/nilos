LIBC_OUT := $(OUT_DIR)/libc

LIBC_OBJS :=\
	stdlib.c.o\
	string.c.o

libc: libc_out $(LIBC_OBJS)

$(filter %.c.o,$(LIBC_OBJS)): %.c.o: $(LIBC_DIR)/src/%.c
	@$(CC) $(CFLAGS) -c $< -o $(LIBC_OUT)/$(notdir $@)

libc_out:
	@mkdir -pv $(LIBC_OUT)
