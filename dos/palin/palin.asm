data segment
	found db 10,13,"String isp alindorme$"
	notfound db 10,13,"String is not palinrome$"
	get db 10,13,"Enter string  $"
	str  db 80,80 dup('$')
	nl db 10,13,"$"
data ends

dispStr macro arg
		push dx
		push ax
        lea dx,arg
        mov ah,09h
        int 21h
		pop ax
		pop dx
endm

        assume ds:data
        assume cs:code
code segment
	start:
        mov ax,data
        mov ds,ax
        mov es,ax

		dispStr get
		lea dx,str
        mov ah,0ah
        int 21h
		mov cl,str+1
		mov ch,0
		lea di,str+2
		lea si,str+2
		add si,cx
		shr cx,1
		dec si
		l1:
			mov al,[di]
			mov bl,[si]
			cmp al,bl
			jnz nf
			inc di
			dec si
			loop l1
		f:
			lea dx,found
			mov ah,09h
			int 21h
			jmp exit
		nf:
			lea dx,notfound
			mov ah,09h
			int 21h
		exit:
			mov ah,4ch
			int 21h
		code ends
	end start
