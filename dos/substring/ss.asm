data segment
	found db 10,13,"String found$"
	notfound db 10,13,"String not found$"
	get1 db 10,13,"Enter string 1 $"
	get2 db 10,13,"Enter string 2 $"
	str1  db 80,80 dup('$')
	str2  db 80,80 dup('$')
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
        mov es,ax

		dispStr get1
		read str1
		dispStr get2
		read str2

		mov ax,1h
		mov dl,str1+1
		mov dh,0

		l1:
			inc ax
			lea si,str1+2
			add si,ax
			lea di,str2+2

			mov cl,str2+1
			mov ch,0h

			repe cmpsb
			je f
			cmp ax,dx
			jnz l1
			jmp nf
		f:
			dispStr found
			jmp exit
		nf:
			dispStr notfound
        exit:
        mov ah,4ch
        int 21h
code ends
end start
