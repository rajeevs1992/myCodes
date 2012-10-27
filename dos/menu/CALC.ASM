data segment
        choice db ?
        opr1 dw ?
        opr2 dw ?
        res  dw ?
        menu db 0ah,0dh,"Enter choice 1.Add 2.Subtract 3.Multiply 4.Divide 5.Exit $"
        get1  db 0ah,0dh,"Enter the number 1 $"
        get2  db 0ah,0dh,"Enter the number 2 $"
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

        dispStr menu
        mov ah,01h
        int 21h
        mov choice,al

        cmp al,35h
        jz ad

        dispStr get1
        read
        mov opr1,ax

        dispStr get2
        read
        mov opr2,ax

        ad:
                cmp choice,31h
                jnz sb
                mov ax,opr1
                mov bx,opr2
                add ax,bx
                mov res,ax
                call dispNum
                jmp start
        sb:
                cmp choice,32h
                jnz ml
                mov ax,opr1
                mov bx,opr2
                sub ax,bx
                mov res,ax
                call dispNum
                jmp start
        ml:
                cmp choice,33h
                jnz divide
                mov ax,opr1
                mov bx,opr2
                mul bx
                mov res,ax
                call dispNum
                jmp start
        divide:
                cmp choice,34h
                jnz exit
                mov ax,opr1
                mov bx,opr2
                mov dx,00h
                div bx
                mov res,ax
                call dispNum
                jmp start
        exit:
        mov ah,4ch
        int 21h
code ends
end start
