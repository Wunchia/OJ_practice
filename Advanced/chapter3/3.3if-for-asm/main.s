	.file	"main.c"
	.intel_syntax noprefix
 # GNU C17 (x86_64-posix-seh-rev0, Built by MinGW-W64 project) version 8.1.0 (x86_64-w64-mingw32)
 #	compiled by GNU C version 8.1.0, GMP version 6.1.2, MPFR version 4.0.1, MPC version 1.1.0, isl version isl-0.18-GMP

 # GGC heuristics: --param ggc-min-expand=100 --param ggc-min-heapsize=131072
 # options passed:  -imultilib .
 # -iprefix D:/Program Files/mingw64/bin/../lib/gcc/x86_64-w64-mingw32/8.1.0/
 # -D_REENTRANT main.c -m32 -masm=intel -mtune=core2 -march=nocona
 # -fverbose-asm
 # options enabled:  -faggressive-loop-optimizations
 # -fasynchronous-unwind-tables -fauto-inc-dec -fchkp-check-incomplete-type
 # -fchkp-check-read -fchkp-check-write -fchkp-instrument-calls
 # -fchkp-narrow-bounds -fchkp-optimize -fchkp-store-bounds
 # -fchkp-use-static-bounds -fchkp-use-static-const-bounds
 # -fchkp-use-wrappers -fcommon -fdelete-null-pointer-checks
 # -fdwarf2-cfi-asm -fearly-inlining -feliminate-unused-debug-types
 # -ffp-int-builtin-inexact -ffunction-cse -fgcse-lm -fgnu-runtime
 # -fgnu-unique -fident -finline-atomics -fira-hoist-pressure
 # -fira-share-save-slots -fira-share-spill-slots -fivopts
 # -fkeep-inline-dllexport -fkeep-static-consts -fleading-underscore
 # -flifetime-dse -flto-odr-type-merging -fmath-errno -fmerge-debug-strings
 # -fpeephole -fplt -fprefetch-loop-arrays -freg-struct-return
 # -fsched-critical-path-heuristic -fsched-dep-count-heuristic
 # -fsched-group-heuristic -fsched-interblock -fsched-last-insn-heuristic
 # -fsched-rank-heuristic -fsched-spec -fsched-spec-insn-heuristic
 # -fsched-stalled-insns-dep -fschedule-fusion -fsemantic-interposition
 # -fset-stack-executable -fshow-column -fshrink-wrap-separate
 # -fsigned-zeros -fsplit-ivs-in-unroller -fssa-backprop -fstdarg-opt
 # -fstrict-volatile-bitfields -fsync-libcalls -ftrapping-math
 # -ftree-cselim -ftree-forwprop -ftree-loop-if-convert -ftree-loop-im
 # -ftree-loop-ivcanon -ftree-loop-optimize -ftree-parallelize-loops=
 # -ftree-phiprop -ftree-reassoc -ftree-scev-cprop -funit-at-a-time
 # -funwind-tables -fverbose-asm -fzero-initialized-in-bss -m32 -m80387
 # -m96bit-long-double -maccumulate-outgoing-args -malign-double
 # -malign-stringops -mcx16 -mfancy-math-387 -mfp-ret-in-387 -mfxsr
 # -mieee-fp -mlong-double-80 -mmmx -mms-bitfields -mno-red-zone -mno-sse4
 # -mpush-args -msahf -msse -msse2 -msse3 -mstack-arg-probe -mstackrealign
 # -mvzeroupper

	.text
	.def	___main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
LC0:
	.ascii "i is small\0"
LC1:
	.ascii "this is loop\0"
	.text
	.globl	_main
	.def	_main;	.scl	2;	.type	32;	.endef
_main:
	push	ebp	 #
	mov	ebp, esp	 #,
	and	esp, -16	 #,
	sub	esp, 32	 #,
 # main.c:3: int main() {
	call	___main	 #
 # main.c:4:     int i=5;
	mov	DWORD PTR [esp+28], 5	 # i,
 # main.c:5:     int j=10;
	mov	DWORD PTR [esp+24], 10	 # j,
 # main.c:6:     if(i<j){
	mov	eax, DWORD PTR [esp+28]	 # tmp89, i
	cmp	eax, DWORD PTR [esp+24]	 # tmp89, j  比较后设置条件码
	jge	L2	 #根据条件码判断，大于等于则跳转至L2,根据ZF，SF来判断
 # main.c:7:         printf("i is small\n");
	mov	DWORD PTR [esp], OFFSET FLAT:LC0	 #将字符串常量LC0的地址放入栈顶,
	call	_puts	 #输出
L2:
 # main.c:9:     for(i=0;i<5;i++){
	mov	DWORD PTR [esp+28], 0	 # i,
 # main.c:9:     for(i=0;i<5;i++){
	jmp	L3	 #无条件转移到L3
L4:
 # main.c:10:         printf("this is loop\n");
	mov	DWORD PTR [esp], OFFSET FLAT:LC1	 #将字符串常量LC1的地址放入栈顶,
	call	_puts	 #
 # main.c:9:     for(i=0;i<5;i++){
	add	DWORD PTR [esp+28], 1	 # i+1,
L3:
 # main.c:9:     for(i=0;i<5;i++){
	cmp	DWORD PTR [esp+28], 4	 # 比较i和4,
	jle	L4	 #,
 # main.c:12:     return 0;
	mov	eax, 0	 # _11,
 # main.c:13: }
	leave	
	ret	
	.ident	"GCC: (x86_64-posix-seh-rev0, Built by MinGW-W64 project) 8.1.0"
	.def	_puts;	.scl	2;	.type	32;	.endef
