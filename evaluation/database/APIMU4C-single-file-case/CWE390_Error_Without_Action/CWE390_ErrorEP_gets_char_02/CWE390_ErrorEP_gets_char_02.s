	.text
	.file	"CWE390_ErrorEP_gets_char_02.c"
	.globl	printLine
	.p2align	4, 0x90
	.type	printLine,@function
printLine:                              # @printLine
	.cfi_startproc
# BB#0:                                 # %entry
	pushq	%rbp
.Ltmp0:
	.cfi_def_cfa_offset 16
.Ltmp1:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Ltmp2:
	.cfi_def_cfa_register %rbp
	movq	%rdi, -8(%rbp)
	popq	%rbp
	retq
.Lfunc_end0:
	.size	printLine, .Lfunc_end0-printLine
	.cfi_endproc

	.globl	globalReturnsTrue
	.p2align	4, 0x90
	.type	globalReturnsTrue,@function
globalReturnsTrue:                      # @globalReturnsTrue
	.cfi_startproc
# BB#0:                                 # %entry
	pushq	%rbp
.Ltmp3:
	.cfi_def_cfa_offset 16
.Ltmp4:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Ltmp5:
	.cfi_def_cfa_register %rbp
	movl	$1, %eax
	popq	%rbp
	retq
.Lfunc_end1:
	.size	globalReturnsTrue, .Lfunc_end1-globalReturnsTrue
	.cfi_endproc

	.globl	globalReturnsFalse
	.p2align	4, 0x90
	.type	globalReturnsFalse,@function
globalReturnsFalse:                     # @globalReturnsFalse
	.cfi_startproc
# BB#0:                                 # %entry
	pushq	%rbp
.Ltmp6:
	.cfi_def_cfa_offset 16
.Ltmp7:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Ltmp8:
	.cfi_def_cfa_register %rbp
	xorl	%eax, %eax
	popq	%rbp
	retq
.Lfunc_end2:
	.size	globalReturnsFalse, .Lfunc_end2-globalReturnsFalse
	.cfi_endproc

	.globl	globalReturnsTrueOrFalse
	.p2align	4, 0x90
	.type	globalReturnsTrueOrFalse,@function
globalReturnsTrueOrFalse:               # @globalReturnsTrueOrFalse
	.cfi_startproc
# BB#0:                                 # %entry
	pushq	%rbp
.Ltmp9:
	.cfi_def_cfa_offset 16
.Ltmp10:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Ltmp11:
	.cfi_def_cfa_register %rbp
	callq	rand
	movl	$2, %ecx
	cltd
	idivl	%ecx
	movl	%edx, %eax
	popq	%rbp
	retq
.Lfunc_end3:
	.size	globalReturnsTrueOrFalse, .Lfunc_end3-globalReturnsTrueOrFalse
	.cfi_endproc

	.globl	CWE390_Error_Without_Action__fgets_char_02_bad
	.p2align	4, 0x90
	.type	CWE390_Error_Without_Action__fgets_char_02_bad,@function
CWE390_Error_Without_Action__fgets_char_02_bad: # @CWE390_Error_Without_Action__fgets_char_02_bad
	.cfi_startproc
# BB#0:                                 # %entry
	pushq	%rbp
.Ltmp12:
	.cfi_def_cfa_offset 16
.Ltmp13:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Ltmp14:
	.cfi_def_cfa_register %rbp
	subq	$144, %rsp
	movabsq	$.L.str, %rdi
	leaq	-112(%rbp), %rax
	xorl	%esi, %esi
	movl	$100, %ecx
	movl	%ecx, %edx
	movq	%rax, %r8
	movq	%rdi, -128(%rbp)        # 8-byte Spill
	movq	%r8, %rdi
	movq	%rax, -136(%rbp)        # 8-byte Spill
	callq	memset
	movq	-136(%rbp), %rax        # 8-byte Reload
	movq	%rax, -120(%rbp)
	movq	-128(%rbp), %rdi        # 8-byte Reload
	callq	printLine
	movl	$100, %esi
	movq	-120(%rbp), %rdi
	movq	stdin, %rdx
	callq	fgets
	cmpq	$0, %rax
	jne	.LBB4_2
# BB#1:                                 # %if.then
	movl	$1, -4(%rbp)
	jmp	.LBB4_3
.LBB4_2:                                # %if.end
	movq	-120(%rbp), %rdi
	callq	printLine
	movl	$1, -4(%rbp)
.LBB4_3:                                # %return
	movl	-4(%rbp), %eax
	addq	$144, %rsp
	popq	%rbp
	retq
.Lfunc_end4:
	.size	CWE390_Error_Without_Action__fgets_char_02_bad, .Lfunc_end4-CWE390_Error_Without_Action__fgets_char_02_bad
	.cfi_endproc

	.globl	CWE390_Error_Without_Action__fgets_char_02_good
	.p2align	4, 0x90
	.type	CWE390_Error_Without_Action__fgets_char_02_good,@function
CWE390_Error_Without_Action__fgets_char_02_good: # @CWE390_Error_Without_Action__fgets_char_02_good
	.cfi_startproc
# BB#0:                                 # %entry
	pushq	%rbp
.Ltmp15:
	.cfi_def_cfa_offset 16
.Ltmp16:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Ltmp17:
	.cfi_def_cfa_register %rbp
	subq	$16, %rsp
	callq	good1
	movl	%eax, -8(%rbp)          # 4-byte Spill
	callq	good2
	movl	-4(%rbp), %ecx
	movl	%eax, -12(%rbp)         # 4-byte Spill
	movl	%ecx, %eax
	addq	$16, %rsp
	popq	%rbp
	retq
.Lfunc_end5:
	.size	CWE390_Error_Without_Action__fgets_char_02_good, .Lfunc_end5-CWE390_Error_Without_Action__fgets_char_02_good
	.cfi_endproc

	.globl	main
	.p2align	4, 0x90
	.type	main,@function
main:                                   # @main
	.cfi_startproc
# BB#0:                                 # %entry
	pushq	%rbp
.Ltmp18:
	.cfi_def_cfa_offset 16
.Ltmp19:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Ltmp20:
	.cfi_def_cfa_register %rbp
	subq	$32, %rsp
	xorl	%eax, %eax
	movl	%eax, %ecx
	movl	$0, -4(%rbp)
	movl	%edi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	%rcx, %rdi
	callq	time
	movl	%eax, %edx
	movl	%edx, %edi
	callq	srand
	movabsq	$.L.str.1, %rdi
	callq	printLine
	callq	CWE390_Error_Without_Action__fgets_char_02_good
	movabsq	$.L.str.2, %rdi
	movl	%eax, -20(%rbp)         # 4-byte Spill
	callq	printLine
	movabsq	$.L.str.3, %rdi
	callq	printLine
	callq	CWE390_Error_Without_Action__fgets_char_02_bad
	movabsq	$.L.str.4, %rdi
	movl	%eax, -24(%rbp)         # 4-byte Spill
	callq	printLine
	xorl	%eax, %eax
	addq	$32, %rsp
	popq	%rbp
	retq
.Lfunc_end6:
	.size	main, .Lfunc_end6-main
	.cfi_endproc

	.p2align	4, 0x90
	.type	good1,@function
good1:                                  # @good1
	.cfi_startproc
# BB#0:                                 # %entry
	pushq	%rbp
.Ltmp21:
	.cfi_def_cfa_offset 16
.Ltmp22:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Ltmp23:
	.cfi_def_cfa_register %rbp
	subq	$144, %rsp
	movabsq	$.L.str, %rdi
	leaq	-112(%rbp), %rax
	xorl	%esi, %esi
	movl	$100, %ecx
	movl	%ecx, %edx
	movq	%rax, %r8
	movq	%rdi, -128(%rbp)        # 8-byte Spill
	movq	%r8, %rdi
	movq	%rax, -136(%rbp)        # 8-byte Spill
	callq	memset
	movq	-136(%rbp), %rax        # 8-byte Reload
	movq	%rax, -120(%rbp)
	movq	-128(%rbp), %rdi        # 8-byte Reload
	callq	printLine
	movl	$100, %esi
	movq	-120(%rbp), %rdi
	movq	stdin, %rdx
	callq	fgets
	cmpq	$0, %rax
	jne	.LBB7_2
# BB#1:                                 # %if.then
	movabsq	$.L.str.5, %rdi
	callq	printLine
	movl	$0, -4(%rbp)
	jmp	.LBB7_3
.LBB7_2:                                # %if.end
	movq	-120(%rbp), %rdi
	callq	printLine
	movl	$1, -4(%rbp)
.LBB7_3:                                # %return
	movl	-4(%rbp), %eax
	addq	$144, %rsp
	popq	%rbp
	retq
.Lfunc_end7:
	.size	good1, .Lfunc_end7-good1
	.cfi_endproc

	.p2align	4, 0x90
	.type	good2,@function
good2:                                  # @good2
	.cfi_startproc
# BB#0:                                 # %entry
	pushq	%rbp
.Ltmp24:
	.cfi_def_cfa_offset 16
.Ltmp25:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Ltmp26:
	.cfi_def_cfa_register %rbp
	subq	$144, %rsp
	movabsq	$.L.str, %rdi
	leaq	-112(%rbp), %rax
	xorl	%esi, %esi
	movl	$100, %ecx
	movl	%ecx, %edx
	movq	%rax, %r8
	movq	%rdi, -128(%rbp)        # 8-byte Spill
	movq	%r8, %rdi
	movq	%rax, -136(%rbp)        # 8-byte Spill
	callq	memset
	movq	-136(%rbp), %rax        # 8-byte Reload
	movq	%rax, -120(%rbp)
	movq	-128(%rbp), %rdi        # 8-byte Reload
	callq	printLine
	movl	$100, %esi
	movq	-120(%rbp), %rdi
	movq	stdin, %rdx
	callq	fgets
	cmpq	$0, %rax
	jne	.LBB8_2
# BB#1:                                 # %if.then
	movabsq	$.L.str.5, %rdi
	callq	printLine
	movl	$0, -4(%rbp)
	jmp	.LBB8_3
.LBB8_2:                                # %if.end
	movq	-120(%rbp), %rdi
	callq	printLine
	movl	$1, -4(%rbp)
.LBB8_3:                                # %return
	movl	-4(%rbp), %eax
	addq	$144, %rsp
	popq	%rbp
	retq
.Lfunc_end8:
	.size	good2, .Lfunc_end8-good2
	.cfi_endproc

	.type	GLOBAL_CONST_TRUE,@object # @GLOBAL_CONST_TRUE
	.section	.rodata,"a",@progbits
	.globl	GLOBAL_CONST_TRUE
	.p2align	2
GLOBAL_CONST_TRUE:
	.long	1                       # 0x1
	.size	GLOBAL_CONST_TRUE, 4

	.type	GLOBAL_CONST_FALSE,@object # @GLOBAL_CONST_FALSE
	.globl	GLOBAL_CONST_FALSE
	.p2align	2
GLOBAL_CONST_FALSE:
	.long	0                       # 0x0
	.size	GLOBAL_CONST_FALSE, 4

	.type	GLOBAL_CONST_FIVE,@object # @GLOBAL_CONST_FIVE
	.globl	GLOBAL_CONST_FIVE
	.p2align	2
GLOBAL_CONST_FIVE:
	.long	5                       # 0x5
	.size	GLOBAL_CONST_FIVE, 4

	.type	globalTrue,@object      # @globalTrue
	.data
	.globl	globalTrue
	.p2align	2
globalTrue:
	.long	1                       # 0x1
	.size	globalTrue, 4

	.type	globalFalse,@object     # @globalFalse
	.bss
	.globl	globalFalse
	.p2align	2
globalFalse:
	.long	0                       # 0x0
	.size	globalFalse, 4

	.type	globalFive,@object      # @globalFive
	.data
	.globl	globalFive
	.p2align	2
globalFive:
	.long	5                       # 0x5
	.size	globalFive, 4

	.type	.L.str,@object          # @.str
	.section	.rodata.str1.1,"aMS",@progbits,1
.L.str:
	.asciz	"Please enter a string: "
	.size	.L.str, 24

	.type	.L.str.1,@object        # @.str.1
.L.str.1:
	.asciz	"Calling good()..."
	.size	.L.str.1, 18

	.type	.L.str.2,@object        # @.str.2
.L.str.2:
	.asciz	"Finished good()"
	.size	.L.str.2, 16

	.type	.L.str.3,@object        # @.str.3
.L.str.3:
	.asciz	"Calling bad()..."
	.size	.L.str.3, 17

	.type	.L.str.4,@object        # @.str.4
.L.str.4:
	.asciz	"Finished bad()"
	.size	.L.str.4, 15

	.type	.L.str.5,@object        # @.str.5
.L.str.5:
	.asciz	"fgets failed!"
	.size	.L.str.5, 14


	.ident	"clang version 3.9.0 (tags/RELEASE_390/final)"
	.section	".note.GNU-stack","",@progbits
