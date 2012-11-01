display macro arg
	lea dx,arg
        mov ah,09h
	int 21h
endm
read macro arg
        local a1,a2
	mov cx,00
	mov si,offset arg
	a1:
		mov ah,01h
		int 21h
		cmp al,13
		jz a2
		mov [si],al
		inc si
		inc cx
		jmp a1
	a2:
		mov bl,"$"
		mov [si],bl
endm
data segment 
	str1 db 0ah,0dh,"enter the string:$"
	str2 db 0ah,0dh,"enter the sub string:$"
	str3 db 0ah,0dh,"present$"
	str4 db 0ah,0dh,"not present$"
	str5 db 0ah,0dh,"palindrom$"
	str6 db 0ah,0dh,"not palindrome$"
	inp1 db 20 dup(?)
	inp2 db 20 dup(?)
	rev2 db 0ah,0dh,20 dup(?)
	d2 db  0ah,0dh,20 dup(?)
	len1 db 0
	len2 db 0
	count db 0
	times db 0
data ends
code segment 
        assume ds:data,cs:code
	start:
		mov ax,data
		mov ds,ax
		
		display str1
		read inp1
                mov len1,cl
                display str2
		read inp2
		mov len2,cl
		mov di,offset inp2
		mov cl,len2
		sub cl,1
		mov si,offset rev2
		S2: inc di
			loop s2
		mov cl,len2
		s1:
			mov al,[di]
			mov [si],al
			inc si
			dec di
			loop s1
		mov al,"$"
		mov [si],al
		display rev2	
		mov si,offset rev2
		mov di,offset inp2
		mov cl,len2
		s3:
			mov al,[si]
			mov dl,[di]
			cmp al,dl
			jnz s4
			inc si
			inc di
			loop s3
			display str5
			jmp s5
		s4:
			display str6
			mov di,offset d2
			mov si,offset inp2
		s6:
			mov al,[si]
			mov dl,"$"
			cmp al,dl
			jz s5
			cmp al,'Z'
			jle s7
			sub al,32
		s7:
			cmp al,'A'
			jge s8
			inc si
			jmp s6
		s8:
			cmp al,'Z'
			jle s9
			inc si
			jmp s6
		s9:
			mov dl,[si]
			mov [di],dl
			inc si
			inc di
			jmp s6

			
		s5:
		mov [di],dl
		display d2
		mov si,offset inp1
		mov di,offset inp2
		mov cl,len1
		
		l1:
			mov al,[si]
			mov dl,[di]
			cmp al,dl
			je l2
		j1:	inc si
			loop l1
			jmp exit
                l2:     push cx
			push si
			push di
		l3:
			inc count
			inc si
			inc di
			mov al,[si]
                        mov dl,[di]
                        cmp al,dl
			je l3
                        mov al,count
                        mov dl,len2
                        cmp al,dl
			je l4
	j2:
			mov al,00
			mov count,al
			pop di
			pop si
                        pop cx
			jmp j1
		l4:
			inc times
			jmp j2
		exit: 	
			mov dl,times
			add dl,30h
			mov ah,02h
			int 21h
			mov ah,4ch
			int 21h
code ends
end start
	

















