	.text
	.def	 @feat.00;
	.scl	3;
	.type	0;
	.endef
	.globl	@feat.00
.set @feat.00, 0
	.file	"example01.c"
	.def	 main;
	.scl	2;
	.type	32;
	.endef
	.globl	main                    # -- Begin function main
	.p2align	4, 0x90
main:                                   # @main
.seh_proc main
# %bb.0:
	pushq	%rax
	.seh_stackalloc 8
	.seh_endprologue
	xorl	%eax, %eax
	movl	$0, 4(%rsp)
	popq	%rcx
	retq
	.seh_handlerdata
	.text
	.seh_endproc
                                        # -- End function
	.def	 decode1;
	.scl	2;
	.type	32;
	.endef
	.globl	decode1                 # -- Begin function decode1
	.p2align	4, 0x90
decode1:                                # @decode1
.seh_proc decode1
# %bb.0:
	subq	$40, %rsp
	.seh_stackalloc 40
	.seh_endprologue
	movq	%r8, 32(%rsp)
	movq	%rdx, 24(%rsp)
	movq	%rcx, 16(%rsp)
	movq	16(%rsp), %rcx
	movl	(%rcx), %eax
	movl	%eax, 12(%rsp)
	movq	24(%rsp), %rcx
	movl	(%rcx), %eax
	movl	%eax, 8(%rsp)
	movq	32(%rsp), %rcx
	movl	(%rcx), %eax
	movl	%eax, 4(%rsp)
	movl	12(%rsp), %eax
	movq	24(%rsp), %rcx
	movl	%eax, (%rcx)
	movl	8(%rsp), %eax
	movq	32(%rsp), %rcx
	movl	%eax, (%rcx)
	movl	4(%rsp), %eax
	movq	16(%rsp), %rcx
	movl	%eax, (%rcx)
	addq	$40, %rsp
	retq
	.seh_handlerdata
	.text
	.seh_endproc
                                        # -- End function
	.def	 test1;
	.scl	2;
	.type	32;
	.endef
	.globl	test1                   # -- Begin function test1
	.p2align	4, 0x90
test1:                                  # @test1
.seh_proc test1
# %bb.0:
	subq	$56, %rsp
	.seh_stackalloc 56
	.seh_endprologue
	movl	$1, 52(%rsp)
	movl	$2, 48(%rsp)
	movl	$3, 44(%rsp)
	leaq	52(%rsp), %rcx
	leaq	48(%rsp), %rdx
	leaq	44(%rsp), %r8
	callq	decode1
	nop
	addq	$56, %rsp
	retq
	.seh_handlerdata
	.text
	.seh_endproc
                                        # -- End function
	.def	 scale;
	.scl	2;
	.type	32;
	.endef
	.globl	scale                   # -- Begin function scale
	.p2align	4, 0x90
scale:                                  # @scale
.seh_proc scale
# %bb.0:
	subq	$24, %rsp
	.seh_stackalloc 24
	.seh_endprologue
	movq	%r8, 16(%rsp)
	movq	%rdx, 8(%rsp)
	movq	%rcx, (%rsp)
	movq	(%rsp), %rcx
	movq	8(%rsp), %rdx
	shlq	$2, %rdx
	addq	%rdx, %rcx
	imulq	$12, 16(%rsp), %rdx
	addq	%rdx, %rcx
	movq	%rcx, %rax
	addq	$24, %rsp
	retq
	.seh_handlerdata
	.text
	.seh_endproc
                                        # -- End function

	.addrsig
	.addrsig_sym decode1
