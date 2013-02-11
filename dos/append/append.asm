data segment
	main db 80 dup('$')
	cons db 80 dup('$')
	rest db 80 dup('$')
	nl db 13,10
	get db "Enter the string $"

data ends

read macro
	lea di,main
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

dispstr macro arg
	lea dx,arg
	mov ah,02h
	int 21h
endm

assume cs:code,ds:data
code segment
		isalpha proc
			cmp ax,90
			jl caps
			sub ax,32
			caps:
				cmp ax,65
				jl false
				cmp ax,90
				jg false
				push ax
				mov ax,1
				ret
			false:
				mov ax,0
				ret
		isalpha endp
		isvow proc
			pop ax
			cmp ax,65
			jz true
			cmp ax,69
			jz true
			cmp ax,73
			jz true
			cmp ax,79
			jz true
			cmp ax,85
			jz true

			mov ax,0
			ret
			true:
				mov ax,1
				ret
		isvow endp
	
	start:
		mov ax,data
		mov ds,ax
		mov es,ax
		dispstr get
		read

		lea bp,rest
		lea si,cons

		lea di,main

		l3:
			pop dx
			mov al,[di]
			cmp al,0
			jz done
			mov ah,0
			call isalpha
			cmp ax,0
			jnz alpha
			mov al,[di]
			mov [bp],al
			inc di
			inc bp
			jmp l3
			alpha:
			call isvow
			cmp ax,0
			jz conso
			mov al,[di]
			mov [bp],al
			inc di
			inc bp
			jmp l3
			conso:
				mov al,[di]
				mov [si],al
				inc di
				inc si
				jmp l3
		mov al,'$'
		mov [bp],al
		mov [si],al
		done:

		dispstr rest
		dispstr nl
		dispstr cons
		mov ah,4ch
		int 21h
	code ends
end start
