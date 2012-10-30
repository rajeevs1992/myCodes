data segment
	n db 80,80 dup("$")
data ends

assume cs:code,ds:data
code segment
	start:
		mov ax,data
		mov ds,ax
;		mov es,ax

		mov ah,0ah
		lea dx,n
		int 21h

		mov ah,3ch
		mov cx,0
		mov al,n+1
		mov bl,n+2

		mov dx,offset n+2
		int 21h
		mov ah,4ch
		int 21h
	code ends
end start
