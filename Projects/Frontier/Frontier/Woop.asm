; PlaySound Library
; This class is for making sounds while in the screen

global _woopSound
global _forloop

extern _sin

section .text
_woopSound:
	push rbx
	mov rbx, 44100 ; Sets number of elements needed

	mov rdi,rbx
	imul rdi,2 ; Sets number of elements times the number of bytes to get the size

	extern _malloc
	call _malloc

	mov r8,44100
	mov rcx,0
	mov rdx,0

	jmp loop


_forloop:
	mov WORD[rax + 2 * rcx],3

	cmp rdx, 200
	jl _cmpIfThousand

	cmp rdx, 300
	jg _cmEndOfWave

	backLoop:
	add rcx,1
	add rdx,1

	loop:
	cmp rcx,r8
	jl _forloop
	je end;

_cmpIfThousand:
	mov WORD[rax + 2*rcx],30000 ; Spaghetti
	jmp backLoop

_cmEndOfWave:
	mov rdx,0
	jmp backLoop

end:
pop rbx
ret
