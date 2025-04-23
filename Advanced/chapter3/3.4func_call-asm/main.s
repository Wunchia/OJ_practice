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
	.globl	_add
	.def	_add;	.scl	2;	.type	32;	.endef
_add:
	push	ebp	 #
	mov	ebp, esp	 #，
	sub	esp, 16	 #给add函数分配16字节的栈空间,
 # main.c:4:     ret=a+b;
	mov	edx, DWORD PTR [ebp+8]	 # tmp93, a，返回地址和main的ebp占用了8个字节，所以+8
	mov	eax, DWORD PTR [ebp+12]	 # tmp94, b，a又占用了4个字节，所以+12
	add	eax, edx	 # tmp92, tmp93
	mov	DWORD PTR [ebp-4], eax	 # ret, tmp92，将eax的值放到ebp-4中，ret的值
 # main.c:5:     return ret;
	mov	eax, DWORD PTR [ebp-4]	 # _4, ret ，将ebp-4的值放到eax中
 # main.c:6: }
	leave	
	ret	#回到调用函数的地方（在call函数时保存的栈顶指针）
	# ret所做的工作 ：
	# mov esp,ebp 将ebp放入esp，此时esp指向了调用函数（main）的栈顶指针
	# pop ebp 将ebp弹栈，恢复ebp的值
	.def	___main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
LC0:
	.ascii "add result=%d\12\0"
	.text
	.globl	_main
	.def	_main;	.scl	2;	.type	32;	.endef
_main:
	push	ebp	 #
	mov	ebp, esp	 #保存esp的值到栈中，ebp指向被调用函数（main）栈底
	and	esp, -16	 #,对齐栈空间，栈空间必须是16的倍数
	sub	esp, 32	 #分配32字节的栈空间
 # main.c:8: int main() {
	call	___main	 #
 # main.c:11:     a=5;
	mov	DWORD PTR [esp+16], 5	 # a,
 # main.c:12:     p=&a;
	lea	eax, [esp+16]	 # tmp91,定义指针，把a的地址放到 eax 中
	mov	DWORD PTR [esp+28], eax	 # p, tmp91，将eax的值放到p中
 # main.c:13:     b=*p+2;
	mov	eax, DWORD PTR [esp+28]	 # tmp92, p，将p的值放到eax中
	mov	eax, DWORD PTR [eax]	 # _1, *p_5，将p指向的内存空间的值放到eax中
 # main.c:13:     b=*p+2;
	add	eax, 2	 # tmp93,运算eax+2
	mov	DWORD PTR [esp+24], eax	 # b, tmp93，将算好的值放到b中
 # main.c:14:     ret=add(a,b);函数调用
	mov	eax, DWORD PTR [esp+16]	 # a.0_2, a，
	mov	edx, DWORD PTR [esp+24]	 # tmp94, b
	mov	DWORD PTR [esp+4], edx	 #, tmp94，将b的值放到esp+4中，传参
	mov	DWORD PTR [esp], eax	 #, a.0_2，将a的值放到esp中，传参
	call	_add	 #调用函数_add
	mov	DWORD PTR [esp+20], eax	 # ret, tmp95，从eax中取出返回值放到esp+20中，在add函数中最后一步已将返回值放到eax中
 # main.c:15:     printf("add result=%d\n",ret);
	mov	eax, DWORD PTR [esp+20]	 # tmp96, ret
	mov	DWORD PTR [esp+4], eax	 #, tmp96 #准备printf的参数
	mov	DWORD PTR [esp], OFFSET FLAT:LC0	 #,
	call	_printf	 #
 # main.c:16:     return 0;
	mov	eax, 0	 # _10,
 # main.c:17: }
	leave	
	ret	
	.ident	"GCC: (x86_64-posix-seh-rev0, Built by MinGW-W64 project) 8.1.0"
	.def	_printf;	.scl	2;	.type	32;	.endef
