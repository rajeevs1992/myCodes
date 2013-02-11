data segment
	sums db 20 dup(0)
	u dw ?
	l dw ?
	get1 db 10,13,"Enter lower limit $"
	get2 db 10,13,"Enter upper limit $"
data ends
read macro
        mov ah,01h
        int 21h
        mov bl,0ah
        sub al,30h
        mul bl
        push ax
        mov ah,01h
        int 21h
        sub al,30h
        mov ah,00h
        pop bx
        add ax,bx        
endm
dispstr macro arg
	lea dx,arg
	mov ah,09h
	int 21h
endm
isprime macro arg
	push ax
	push bx
	push cx
	push dx
	mov ax,arg
	mov cx,arg
	dec cx
	l4:
		div cx
		cmp dx,0
		jz l5
		mov ax,arg
		cmp cx,02h
		jz l5
		loop l4
	l5:
		cmp cx,2
		jz 
	

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

		dispstr get1
		read
		mov l,ax
		dispstr get2
		read
		mov u,ax

		mov cx,u
		mov bx,l

		l3:
			mov cur,bx
			inc bx
			isprime cur
			
