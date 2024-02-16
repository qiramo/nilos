.org 32

.set ALIGN, 1 << 0
.set MEMINFO, 1 << 1
.set FLAGS, ALIGN | MEMINFO
.set MAGIC, 0x1BADB002
.set CHECKSUM, -(MAGIC + FLAGS)

.section .multiboot
	.align 4
	.long MAGIC
	.long FLAGS
	.long CHECKSUM

.section .bss
	.align 16
	stack_base:
		.skip 0x4000 # 16KB
	stack_top:

.section .text
	.global _start
	_start:
		movl $stack_top, %esp

		cli
		call kernel_early_main

		call _init
		call kernel_main

	halt:
		hlt
		jmp halt

.size _start, . - _start
