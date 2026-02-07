	.file	"main.c"
 # GNU C23 (Rev5, Built by MSYS2 project) version 15.1.0 (x86_64-w64-mingw32)
 #	compiled by GNU C version 15.1.0, GMP version 6.3.0, MPFR version 4.2.2, MPC version 1.3.1, isl version isl-0.27-GMP

 # GGC heuristics: --param ggc-min-expand=100 --param ggc-min-heapsize=131072
 # options passed: -mtune=generic -march=nocona -O2
	.text
	.section	.text.startup,"x"
	.p2align 4
	.globl	main
	.def	main;	.scl	2;	.type	32;	.endef
	.seh_proc	main
main:
	subq	$40, %rsp	 #,
	.seh_stackalloc	40
	.seh_endprologue
 # main.c:4: int main(void) {
	call	__main	 #
 # main.c:10: }
	movl	$202, %eax	 #,
	addq	$40, %rsp	 #,
	ret	
	.seh_endproc
	.def	__main;	.scl	2;	.type	32;	.endef
	.ident	"GCC: (Rev5, Built by MSYS2 project) 15.1.0"
