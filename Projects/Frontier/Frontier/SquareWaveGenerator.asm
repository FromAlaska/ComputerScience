; Jim Samson
; October 15, 2017
; CS301 Assembly Language

; Square Wave Generator
; This class is for making sounds while in the screen.
; This takes an 64-bit integer.
; Similar to C code squareWaveGenerator(int)

; How to use this code:
;	- This program returns a pointer.
;	- Call extern "C" short * squareWaveGenerator(int)
;	- This is built for the Apple Macbook Late 2013.
;	- I use the SFML Library, with the sf::SoundBuffer _soundBuffer; & sf::Sound _sound
;	- Documentation on _nameBuffer.loadfromsamples(short *, Sample Size, channel(1,2),Sample Rate);
;	- It's also same for Sound API functions that use
;										_nameBuffer.loadfromsamples(short *, Sample Size, channel(1,2),Sample Rate);
;	- I load the pointer into a buffer, using _soundBuffer.loadfromsamples(soundWaveGenerator(int),44100,1,44100);

; Example of this code:
;	- This function is defined in the SounManager.hpp class.
;	- Inside loadBuffer(short*,44100,1,44100), the buffer is loaded from samples


global _squareWaveGenerator

section .text
_squareWaveGenerator:

	; Loads an rdi (64-bit integer) input into registers
	mov r9,rdi
	mov r10,r9

	push rbx
	mov rbx, 44100 					; Sets the SAMPLE Size

	mov rdi,rbx						; Moves 44100 input
	imul rdi,2 						; Sets number of elements times the number of bytes to get the size

	extern _malloc 					; 88200 bytes
	call _malloc

	; placeholder registers
	mov r8,44100
	mov rcx,0						; i = 0
	mov rdx,0						; n = 0

	jmp loop

_forloop:
	mov WORD[rax + 2 * rcx],0 			; Amplitude

	cmp rdx, 50 						; Compares the first length of the wave to 30 KHZ
	jl _cmpIfThousand

	cmp rdx, 100 						;Compares the second length of the wave, which sets the value back to a wave
	jg _cmEndOfWave

	backLoop:
	add rcx,1 ; i++
	add rdx,1 ; n++

	loop:
	cmp rcx,r8 							; Compares if we got to the end of the array
	jl _forloop
	je end;

_cmpIfThousand:
	mov WORD[rax + 2 * rcx],30000 		; Load top wave to 30,000
	jmp backLoop

; This compares a number with the integer that was passed into the function
; This is the integer from the rdi input that needs to be compared.

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

; This loads the bottom wave of the array
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

; End of the loop, returns a short *
end:
pop rbx
ret
