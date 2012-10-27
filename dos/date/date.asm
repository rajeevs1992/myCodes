data segment
	num dw ?
	hr db ?
	min db ?
	sec db ?
	ms db ?
	date db ?
	mnth db ?
	yr dw ?
data ends
assume cs:code,ds:data
code segment
	dispnum proc
		mov bx,0ah
		mov cx,0h
		l1:
			mov dx,00h
			div bx
			push dx
			inc cx
			cmp ax,0h
			jnz l1
		l2:
			pop dx
			mov ah,02h
			add dx,30h
			int 21h
			loop l2
		mov dx,':'
		int 21h
		ret
	dispnum endp
start:
	mov ax,data
	mov ds,ax
	mov es,ax
	l3:
	mov ah,2ch
	int 21h
	mov hr,ch
	mov min,cl
	mov sec,dh
	mov ms,dl
	mov ax,0
	mov al,hr
	call dispnum
	mov ax,0
	mov al,min
	call dispnum
	mov ax,0
	mov al,sec
	call dispnum
	mov ax,0
	mov al,ms
	call dispnum
	mov ax,0

	mov ah,2ah
	int 21h
	mov yr,cx
	mov date,dh
	mov mnth,dl

	mov dx,0dh
	mov ah,02h
	int 21h
	jmp l3


;	mov ax,0
;	mov al,date
;	call dispnum
;	mov ax,0
;	mov al,mnth
;	call dispnum
;	mov ax,yr
;	call dispnum

	mov ah,4ch
	int 21h
code ends
end start
