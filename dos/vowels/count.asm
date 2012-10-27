data segment
		v  dw 0
		c  dw 0
        get  db 0ah,0dh,"Enter the string $"
        dia1  db 0ah,0dh,"The number of vowels is $"
        dia2  db 0ah,0dh,"The number of consonants is $"
data ends
dispStr macro arg
        lea dx,arg
        mov ah,09h
        int 21h
endm
read macro
        mov ah,01h
        int 21h
		mov ah,00h
endm
vowel macro arg1,arg2
	cmp ax,arg1
	jnz arg2
	mov bx,v
	inc bx
	mov v,bx
	jmp l3
endm
num macro dia,value,label1,label2
        dispStr dia
        mov cx,00h
        mov ax,value
        mov bx,0ah
        label1:
                mov dx,00h
                div bx
                push dx
                inc cx
                cmp ax,00h
                jnz label1
        label2:
                pop dx
                add dx,30h
                mov ah,02h
                int 21h
                loop label2
endm
assume ds:data,cs:code
code segment
dispNum proc
	num dia1 v l1 l2
	num dia2 c l4 l5
    ret
dispNum endp
start:
    mov ax,data
    mov ds,ax
	dispStr get
	l3:
		read
		cmp ax,0dh
		jz a
		cmp ax,61h
		jl caps
		sub ax,20h
		caps:
		cmp ax,41h
		jl l3
		cmp ax,5ah
		jg l3
		a:vowel 41h,e
		e:vowel 45h,i
		i:vowel 49h,o
		o:vowel 4fh,u
		u:vowel 55h,cons
		cons:
			cmp ax,0dh
			jz exit
			mov bx,c
			inc bx
			mov c,bx
			jmp l3
        exit:
			call dispNum
        	mov ah,4ch
	        int 21h
code ends
end start
