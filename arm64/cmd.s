/**
  execute command using /bin/sh
  tested with linux running on ubuntu

  http://modexp.wordpress.com/  
*/

// 72 bytes
    .global _start
    .text

_start:
    // execve("/bin/sh", {"/bin/sh", "-c", cmd, NULL}, NULL);
    eor    x3, x3, x3     // x3 = NULL
    
    adr    x0, sh         // r0 = "/bin/shX"
    strb   x3, [x0, #7]   // add null terminator
    
    adr    x1, c_arg      // r1 = "-cXX"
    strb   x3, [x1, #2]   // add null terminator

    adr    x2, cmd        // r4 = cmd
    strb   x3, [x2, #18]  // add null terminator
    
    push   {x0, x1, x2, x3}
    eor    x2, x2, x2     // penv = NULL
    mov    x1, sp         // r1 = argv
    mov    x8, #11        // r7 = execve
    svc    1  
sh:    
.ascii "/bin/shX"
c_arg:
.ascii "-cXX"
cmd:
.ascii "echo Hello, World!"

