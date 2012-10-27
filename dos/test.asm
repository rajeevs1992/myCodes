data segment
	array dw 20 dup(?)
	limit dw ?
data ends
readnum proc
	mov ax,0h
	
	mov ah,01h
	int 21h

assume cs:code,ds:data
code segment
	start:
		mov ax,data
		mov ds,ax
		mov es,ax
code ends 
end start
