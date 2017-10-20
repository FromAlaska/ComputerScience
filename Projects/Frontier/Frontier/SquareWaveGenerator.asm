; Square Wave Generator
; This class is for making sounds while in the screen
; This takes an integer (64 bit)
; Similar to C code squareWaveGenerator(int)

global _squareWaveGenerator

section .text
_squareWaveGenerator:

	; Loads hertz into a registers
	mov r9,rdi
	mov r10,r9

	push rbx
	mov rbx, 44100 ; Sets the SAMPLE Size

	mov rdi,rbx
	imul rdi,2 ; Sets number of elements times the number of bytes to get the size

	extern _malloc
	call _malloc

	; placeholder registers
	mov r8,44100
	mov rcx,0
	mov rdx,0

	jmp loop


_forloop:
	mov WORD[rax + 2 * rcx],30 ; Amplitude

	cmp rdx, 50 ; Compares the first length of the wave to 30 KHZ
	jl _cmpIfThousand

	cmp rdx, 100 ;Compares the second length of the wave, which sets the value back to a wave
	jg _cmEndOfWave

	backLoop:
	add rcx,1 ; i++
	add rdx,1 ; n++

	loop:
	cmp rcx,r8 ; Compares if we got to the end of the array
	jl _forloop
	je end;

_cmpIfThousand:
	mov WORD[rax + 2 * rcx],30000 ; Spaghetti
	jmp backLoop

; This compares a number with the integer that was passed into the function
_cmEndOfWave:
	cmp r10,1
	je cWave

	cmp r10,2
	je dWave

	cmp r10,3
	je eWave

	cmp r10,4
	je fWave

	cmp r10,5
	je gWave

	cmp r10,6
	je aWave

	cmp r10,7
	je bWave

cWave:
	mov rdx,10
	jmp backLoop
dWave:
	mov rdx,15
	jmp backLoop
eWave:
	mov rdx,20
	jmp backLoop
fWave:
	mov rdx,25
	jmp backLoop
gWave:
	mov rdx,30
	jmp backLoop
aWave:
	mov rdx,35
	jmp backLoop
bWave:
	mov rdx,40
	jmp backLoop


end:
pop rbx
ret
