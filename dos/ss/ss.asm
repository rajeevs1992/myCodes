data segment
		res  dw 0
        get1  db 0ah,0dh,"Enter the string $"
        get2  db 0ah,0dh,"Enter the substring $"
        found  db 0ah,0dh,"The substring was found $"
        notfound  db 0ah,0dh,"The substring was not found $"
		s1 db "string",0
		s2 db "string",0
		sz equ $-s2
		str db 80
			db 0
			db 80 dup('$')
		substr db 10
		       db 0
			   db 10 dup('$')
data ends

dispStr macro arg
        lea dx,arg
        mov ah,09h
        int 21h
endm

read macro arg
	lea dx,arg
    mov ah,0ah
    int 21h
endm

assume ds:data
assume cs:code
code segment
start:
mov ax,data
mov ds,ax
	mov si,offset s1
	mov di,offset s2
	mov cx,sz
	cld
	repe cmpsb
	jnz nota
	dispStr found
	jmp exit
	nota:
		dispStr notfound
    exit:
    	mov ah,4ch
        int 21h
code ends
end start
