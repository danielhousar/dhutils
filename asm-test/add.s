	.file	"add.c"
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC0:
	.string	"%d\n"
	.section	.text.startup,"ax",@progbits
	.p2align 4,,15
	.globl	main
	.type	main, @function
main:
.LFB11:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	xorl	%eax, %eax
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	andl	$-16, %esp
	subl	$16, %esp			#
	cmpl	$1, 8(%ebp)			# compare 1 to argv[1][0]
	jle	.L2				# jump on less
	movl	12(%ebp), %eax
	movl	4(%eax), %eax		#
	movsbl	(%eax), %eax	#
	subl	$48, %eax			# b - 48
.L2:
	addl	$3, %eax			# b + 3
	movl	%eax, 4(%esp)
	movl	$.LC0, (%esp)		# "%d\n"
	call	printf			# printf()
	movl	stdin, %eax			# stdin to EAX
	movl	%eax, (%esp)		#
	call	_IO_getc			# getchar()
	xorl	%eax, %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE11:
	.size	main, .-main
	.ident	"GCC: (GNU) 4.6.1"
	.section	.note.GNU-stack,"",@progbits
