data segment
	str db 80,80 dup('$')
	fname db 80,80 dup('$')
	getname db 10,13,"Enter name $"
	cwds db 10,13,"The current working directory is $"
	menu db 10,13,"Enter choice 1 touch 2 mkdir 3 pwd 4 rm 5 rmdir 6 exit $"
	choice db 0
data ends

readchar macro
	mov ah,01h
	int 21h
endm

readstr macro arg2
	local l1,l2
	lea di,arg2
	mov ah,01h
	l1:
		int 21h
		cmp al,0dh
		je l2
		mov [di],al
		inc di
		jmp l1
	l2:
		mov al,0
		mov [di],al
endm
dispstr macro arg3
	lea dx,arg3
	mov ah,09h
	int 21h
	mov ax,0h
endm

assume cs:code,ds:data
code segment
	start:
		mov ax,data
		mov ds,ax
		mov es,ax

		mainloop:
			dispstr menu
			readchar
			mov ah,0h
			touch:
				cmp ax,31h
				jnz mkdir
				dispstr getname
				readstr fname
				lea dx,fname
				mov cx,0
				mov ah,3ch
				int 21h
				jmp mainloop
			mkdir:
				cmp ax,32h
				jnz pwd
				dispstr getname
				readstr fname
				lea dx,fname
				mov ah,39h
				mov cx,0
				int 21h
				jmp mainloop
			pwd:
			 	cmp ax,33h
			 	jnz rm
				mov dx,0
			 	lea si,str
			 	mov ah,47h
			  	int 21h
			 	dispstr cwds
			 	dispstr str
			 	jmp mainloop
			rm:
			 	cmp ax,34h
			 	jnz rmdir
				mov cx,0
				dispstr getname
			 	readstr fname
			 	lea dx,fname
			 	mov ah,41h
			 	int 21h
			 	jmp mainloop
			rmdir:
			 	cmp ax,35h
			 	jnz exit
				mov cx,0
				dispstr getname
			 	readstr fname
			 	lea dx,fname
			 	mov ah,3ah
			 	int 21h
			 	jmp mainloop
			exit:
				mov ah,4ch
				int 21h
		code ends
end start
