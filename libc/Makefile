LIBC_OBJS :=\
	stdlib.c.o\
	string.c.o

libc: $(LIBC_OBJS)

$(filter %.c.o,$(LIBC_OBJS)): %.c.o: $(LIBCDIR)/src/%.c
	@$(CC) $(CFLAGS) -c $< -o $(OBJDIR)/$(@F:%.c.o=%.o)
