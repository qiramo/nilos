.org 32

.section .text
	.global gdt_load
	gdt_load:
		movl 4(%esp), %eax
		lgdt (%eax)

		movw $0x10, %ax # 0x10 is 16. 16 is the offset of the data segment
		movw %ax, %ds
		movw %ax, %es
		movw %ax, %fs
		movw %ax, %gs
		movw %ax, %ss

		jmp $0x8, $far_jump_cs # 0x8 is 8. 8 is the offset of the code segment

	far_jump_cs:
		ret
