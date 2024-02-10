ROOTDIR := $(dir $(firstword $(MAKEFILE_LIST)))

ARCHDIR := $(ROOTDIR)arch
KERNELDIR := $(ROOTDIR)kernel
LIBCDIR := $(ROOTDIR)libc

BUILDDIR := $(ROOTDIR)build
OBJDIR := $(BUILDDIR)/obj

INCLUDES :=\
	$(LIBCDIR)/inc\
	$(KERNELDIR)/inc

INCLUDES := $(addprefix -I,$(INCLUDES))

CC := gcc
CFLAGS := -nostdlib -ffreestanding -fno-builtin -fno-stack-protector\
	-Wall -Wextra -Werror $(INCLUDES)

.PHONY: clean x86

x86: dirs libc kernel x86_arch
include $(ARCHDIR)/x86/Makefile

include $(LIBCDIR)/Makefile
include $(KERNELDIR)/Makefile

dirs:
	@mkdir -pv $(OBJDIR)

clean:
	@rm -rf $(BUILDDIR)
