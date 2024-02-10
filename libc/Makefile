LIBC_SRCS :=\
	stdlib.c\
	string.c

LIBC_SRCS := $(addprefix $(LIBCDIR)/src/,$(LIBC_SRCS))
LIBC_OBJS := $(LIBC_SRCS:%=%.o)

libc: $(LIBC_OBJS)

%.c.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $(OBJDIR)/$(@F)
