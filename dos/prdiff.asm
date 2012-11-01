display macro arg
lea dx,arg
mov ah,09h
int 21h
endm

read macro
mov ah,01h 
int 21h
mov bl,0ah
mov ah,00h
sub al,30h
mul bl
push ax
mov ah,01h
int 21h
sub al,30h
mov ah,00h
pop dx
add ax,dx
endm

data segment
a db ?
b db ?
c db ?
array db 40 dup(0)
msg1 db 0ah,0dh,"enter the lower limit : $"
msg2 db 0ah,0dh,"enter the upper limit: $"
msg3 db 0ah,0dh,"prime number: $"
msg4 db 0ah,0dh,"difference: $"
data ends

assume cs:code,ds:data

code segment
start:
mov ax,data
mov ds,ax

lea si,array
display msg1
read
mov a,al
display msg2
read 
mov b,al

mov bh,0ah
mov ch,00h
mov cl,a

l1:
mov bl,02h

l1a:
mov al,cl
mov ah,00h
div bl
cmp ah,00h
jz l2
inc bl
cmp bl,cl
jnz l1a

prime_display:
mov [si],cl
inc si
display msg3
mov al,cl
mov ah,00h
div bh
mov c,ah
add al,30h
mov dl,al
mov ah,02h
int 21h
mov dl,c
add dl,30h
int 21h

l2:
inc cl
cmp cl,b
jnz l1

lea di,array
dec si
mov bh,0ah

l3:
display msg4
mov ah,[di]
inc di
mov al,[di]
sub al,ah
mov ah,00h
div bh
mov c,ah
add al,30h
mov dl,al
mov ah,02h
int 21h
mov dl,c
add dl,30h
int 21h
cmp di,si
jnz l3

mov ah,4ch
int 21h

code ends
end start

