display macro arg
lea dx,arg
mov ah,09h
int 21h
endm

read macro
mov ah,01h
int 21h
sub al,30h
mov bl,0ah
mov ah,00h
mul bl
push ax
mov ah,01h
int 21h
sub al,30h
mov ah,00h
pop dx
add ax,dx
mov var,al
endm

data segment
array db 40 dup("$")
siz db ?
var db ?
msg1 db 0ah,0dh,"enter the siz of array as a two digit num : $"
msg2 db 0ah,0dh,"enter the element as a two digit num : $"
msg3 db 0ah,0dh,"enter the element to be inserted : $"
msg4 db 0ah,0dh,"the sorted list is : $"
msg5 db 0ah,0dh,"$"
data ends




code segment
assume cs:code,ds:data
start:
mov ax,data
mov ds,ax

display msg1
read
mov al,var
mov siz,al
mov ch,00h
mov cl,siz
lea si,array
add si,02h

l1:
display msg2
read
mov al,var
mov [si],al
inc si
loop l1

display msg3
read
mov ch,00h
mov cl,siz
lea si,array
add si,02h

l2:
mov al,[si]
cmp var,al
jle insert
inc si
loop l2

insert:
inc cx
mov di,si
mov al,[si]
mov dl,var
mov [si],dl
inc di

l3:
mov dl,[di]
mov [di],al
inc di
mov al,dl
loop l3

lea si,array
add si,02h
mov ch,00h
mov cl,siz
inc cx
mov bl,0ah

display msg4
l4:
display msg5
mov ax,0000h
mov al,[si]
div bl
mov bh,ah
mov dl,al
add dl,30h
mov ah,02h
int 21h
mov dl,bh
add dl,30h
mov ah,02h
int 21h
inc si
loop l4

mov ah,4ch
int 21h

code ends 
end start

