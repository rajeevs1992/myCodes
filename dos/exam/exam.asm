;Read a sentence
;Remove special char
;Search for your name in the new string
data segment
	nam db 40,40 dup("$")
	main db 80 dup("$")	
	get db 10,13,"Enter the string $"
	getn db 10,13,"Enter the name $"
	found db 10,13,"Name found $"
	notfound db 10,13,"Name not found $"
data ends

assume cs:code,ds:data
code segment
	start:
		mov ax,data
		mov ds,ax
		mov es,ax

		lea dx,get
		mov ah,09h
		int 21h

		lea di,main
		mov ah,01h
		l1:
			int 21h
			cmp al,0dh
			jz comp
			cmp al,122
			jg l1
			cmp al,'Z'
			jl caps
			sub al,32
			caps:
				cmp al,'A'
				jl l1
				add al,32
				mov [di],al
				inc di
				jmp l1
		comp:
			mov al,0
			mov [di],al
			lea dx,getn
			mov ah,09h
			int 21h

			lea dx,nam
			mov ah,0ah
			int 21h

			mov ax,0
			l2:
				lea si,main
				lea di,nam+2
				mov cl,nam+1
				mov ch,00
				add si,ax
				inc ax

				mov bl,[si]
				cmp bl,0
				jz nf

				repe cmpsb
				je f

				jmp l2
			nf:
				lea dx,notfound
				mov ah,09h
				int 21h
				jmp exit
			f:
				lea dx,found
				mov ah,09h
				int 21h
		exit:
			mov ah,4ch
			int 21h
code ends 
end start
