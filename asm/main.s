	.file	"main.c"
 # GNU C23 (Rev5, Built by MSYS2 project) version 15.1.0 (x86_64-w64-mingw32)
 #	compiled by GNU C version 15.1.0, GMP version 6.3.0, MPFR version 4.2.2, MPC version 1.3.1, isl version isl-0.27-GMP

 # GGC heuristics: --param ggc-min-expand=100 --param ggc-min-heapsize=131072
 # options passed: -mtune=generic -march=nocona -O0
	.text
	.globl	someConstValue
	.section .rdata,"dr"
	.align 4
someConstValue:
	.long	12036
	.text
	.globl	main
	.def	main;	.scl	2;	.type	32;	.endef
	.seh_proc	main
main:
	pushq	%rbp	 #
	.seh_pushreg	%rbp
	movl	$4848, %eax	 #,
	call	___chkstk_ms
	subq	%rax, %rsp	 #,
	.seh_stackalloc	4848
	leaq	128(%rsp), %rbp	 #,
	.seh_setframe	%rbp, 128
	.seh_endprologue
 # main.c:5: int main(void) {
	call	__main	 #
 # main.c:6:   int a = 0;
	movl	$0, 4716(%rbp)	 #, a
 # main.c:10:   for(int i = 0; i < 1200; i++) {
	movl	$0, 4712(%rbp)	 #, i
 # main.c:10:   for(int i = 0; i < 1200; i++) {
	jmp	.L2	 #
.L3:
 # main.c:12:     a+= arr[i];
	movl	4712(%rbp), %eax	 # i, tmp102
	cltq
	movl	-96(%rbp,%rax,4), %eax	 # arr[i_3], _1
 # main.c:12:     a+= arr[i];
	addl	%eax, 4716(%rbp)	 # _1, a
 # main.c:10:   for(int i = 0; i < 1200; i++) {
	addl	$1, 4712(%rbp)	 #, i
.L2:
 # main.c:10:   for(int i = 0; i < 1200; i++) {
	cmpl	$1199, 4712(%rbp)	 #, i
	jle	.L3	 #,
 # main.c:15:   return someConstValue;
	movl	$12036, %eax	 #, _6
 # main.c:16: }
	addq	$4848, %rsp	 #,
	popq	%rbp	 #
	ret	
	.seh_endproc
	.def	__main;	.scl	2;	.type	32;	.endef
	.ident	"GCC: (Rev5, Built by MSYS2 project) 15.1.0"
