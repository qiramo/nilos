ROOT_DIR := $(dir $(firstword $(MAKEFILE_LIST)))

ARCH_DIR := $(ROOT_DIR)arch
KERNEL_DIR := $(ROOT_DIR)kernel
LIBC_DIR := $(ROOT_DIR)libc

BUILD_DIR := $(ROOT_DIR)build
OUT_DIR := $(BUILD_DIR)/out

INCLUDES :=\
	$(LIBC_DIR)/inc\
	$(KERNEL_DIR)/inc

INCLUDES := $(addprefix -I,$(INCLUDES))

CC := gcc
CFLAGS := -nostdlib -ffreestanding -fno-builtin -fno-stack-protector\
	-Wall -Wextra -Werror $(INCLUDES)

.PHONY: clean x86

x86: libc kernel x86_arch
include $(ARCH_DIR)/x86/Makefile

include $(LIBC_DIR)/Makefile
include $(KERNEL_DIR)/Makefile

clean:
	@rm -rf $(BUILD_DIR)
