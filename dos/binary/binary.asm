data segment
		res  dw 0
        get  db 0ah,0dh,"Enter the number $"
        r  db 0ah,0dh,"The result is $"
data ends

dispStr macro arg
        lea dx,arg
        mov ah,09h
        int 21h
endm

read macro
        mov ah,01h
        int 21h
endm
        assume ds:data
        assume cs:code
code segment
dispNum proc
        dispStr r
        mov cx,00h
        mov ax,res
        mov bx,0ah
        l1:
                mov dx,00h
                div bx
                push dx
                inc cx
                cmp ax,00h
                jnz l1
        l2:
                pop dx
                add dx,30h
                mov ah,02h
                int 21h
                loop l2
        ret
dispNum endp
start:
        mov ax,data
        mov ds,ax
		mov bx,0
        dispStr get
		l3:
	        read
			mov ah,00h
			cmp ax,0dh
			jz done
			sal bx,1h
			cmp ax,31h
			jnz zero
			or bx,1h
			jmp l3
			zero:
				jmp l3
		done:
			mov res,bx
            call dispNum
        exit:
        mov ah,4ch
        int 21h
code ends
end start
