;
;  Copyright © 2017 Odzhan. All Rights Reserved.
;
;  Redistribution and use in source and binary forms, with or without
;  modification, are permitted provided that the following conditions are
;  met:
;
;  1. Redistributions of source code must retain the above copyright
;  notice, this list of conditions and the following disclaimer.
;
;  2. Redistributions in binary form must reproduce the above copyright
;  notice, this list of conditions and the following disclaimer in the
;  documentation and/or other materials provided with the distribution.
;
;  3. The name of the author may not be used to endorse or promote products
;  derived from this software without specific prior written permission.
;
;  THIS SOFTWARE IS PROVIDED BY AUTHORS "AS IS" AND ANY EXPRESS OR
;  IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
;  WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
;  DISCLAIMED. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT,
;  INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
;  (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
;  SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
;  HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
;  STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
;  ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
;  POSSIBILITY OF SUCH DAMAGE.
;
    bits   32

struc pushad_t
  _edi resd 1
  _esi resd 1
  _ebp resd 1
  _esp resd 1
  _ebx resd 1
  _edx resd 1
  _ecx resd 1
  _eax resd 1
  .size:
endstruc

; VOID invoke_api(DWORD api_hash, LPVOID api_parameters[]);
invoke_api:
    pushad
    xor    eax, eax
    mov    eax, [fs:eax+30h]  ; eax = (PPEB) __readfsdword(0x30);
    mov    eax, [eax+0ch]  ; eax = (PPEB_LDR_DATA)peb->Ldr
    mov    edi, [eax+0ch]  ; edi = ldr->InLoadOrderModuleList.Flink
    jmp    get_base
next_module:    
    mov    edi, [edi]     ; edi = dte->InLoadOrderLinks.Flink
get_base:
    mov    ebx, [edi+18h] ; ebx = dte->DllBase
    ; eax = IMAGE_DOS_HEADER.e_lfanew
    mov    eax, [ebx+3ch]
    ; ecx = IMAGE_DATA_DIRECTORY.VirtualAddress
    mov    ecx, [ebx+eax+78h]
    jecxz  next_module
    ; esi = api_hash(IMAGE_EXPORT_DIRECTORY.Name)
    mov    esi, [ebx+ecx+0ch]
    add    esi, ebx
    xor    eax, eax
    cdq             ; h = 0
hash_dll:
    lodsb
    or     al, 20h
    add    edx, eax ; h += (*s++ | 0x20)
    ror    edx, 13  ; h = ROTR32(h, 13) 
    dec    eax      ; while (
    jns    hash_dll    
    mov    ebp, edx
    
    ; esi = offset IMAGE_EXPORT_DIRECTORY.NumberOfNames 
    lea    esi, [ebx+ecx+18h]
    lodsd
    xchg   eax, ecx
    jecxz  next_module        
    ; esi = IMAGE_EXPORT_DIRECTORY.AddressOfFunctions     
    lodsd
    add    eax, ebx
    push   eax    
    ; edx = IMAGE_EXPORT_DIRECTORY.AddressOfNames
    lodsd
    lea    edx, [eax+ebx]
    ; edi = IMAGE_EXPORT_DIRECTORY.AddressOfNameOrdinals
    lodsd
    add    eax, ebx
    push   eax
get_name:
    mov    esi, [edx+4*ecx-4] ; eax = RVA of API string
    add    esi, ebx           ; eax = RVA2VA(eax, ebx)
    xor    eax, eax
    cdq    
hash_name:    
    lodsb    
    add    edx, eax
    ror    edx, 13
    dec    eax
    jns    hash_name
    add    eax, ebp           ; add hash of DLL string

    cmp    eax, [esp+_ecx]    ; found match?
    loopne get_name           ; --ecx && eax != hash
    pop    esi
    pop    edx
    jne    next_module        ; get next DLL

    xchg   eax, ebx           ; swap(hash, dll_base)
    xchg   eax, ecx           ; swap(dll_base, ordinal_idx)

    movzx  eax, word [edx+2*eax] ; eax = AddressOfNameOrdinals[eax]
    add    ecx, [esi+4*eax]      ; ecx = base + AddressOfFunctions[eax]
    pop    edi                   ; release edi
    push   ecx                   ; save ecx in its place 
    popad                        ; restore all
    jmp    edi                   ; jmp into api  
    