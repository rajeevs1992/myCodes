section .data
	input 	: db '?'
	len 	: equ $-input
	msg		: db 'Palindrome!!!',10
	msgE	: db 'Not palindrome!!!',10


section .text
	global main
main:
;	mov ax,3
;	mov bx,0
;	mov cx,input
;	mov dx,9
;	int 0x80
;	mov di,input
;	mov si,len
;	mov cx,len
;	loop1:
;		mov al,byte [si]
;		mov bh,byte [di]
;		inc di
;		dec si
;		cmp ax,bx
;		jne error
;;		loop loop1
;	jmp success
;	error:
		mov ax,4
		mov bx,1
;		mov cx,msgE
;		mov dx,18
		int 0x80
		jmp exit
;	success:
		mov ax,4
		mov bx,1
;		mov cx,msg
;		mov dx,14
		int 0x80
		jmp exit
	exit:
