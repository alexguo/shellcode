/**
  execute /bin/sh
  tested with linux running on raspberry pi 3 

  http://modexp.wordpress.com/   
*/

    .global _start
    .text

_start:
    // execve("/bin/sh", NULL, NULL);
    adr    x0, sh         // r0 = "/bin/sh"
    eor    x1, x1, x1     // r1 = NULL
    eor    x2, x2, x2     // r2 = NULL
    //strb   w2, [x0, #7]   // add null terminator
    mov    x8, #221        // r7 = execve
    svc    1
sh:    
    .ascii "/bin/sh\0"
