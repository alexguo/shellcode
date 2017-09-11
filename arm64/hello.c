
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  int i, r;
  uint64_t x;
  
  for (i=0; i<argc; i++) {
    printf ("argv[%i]: %s\n", i, argv[i]);
  }

  r = atoi(argv[1]);
  x = (r * r);

  for (i=argc-1; i>0; i--) {
    printf ("argv[%i]: %s\n", i, argv[i]);
  }
  
  return 0;
}
