/**
  switch to thumb mode on ARM
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