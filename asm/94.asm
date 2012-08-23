global main
main:
	mov eax,3
	mov ebx,0
	mov ecx,[ebp]
	mov edx,[ebp+8]
	int 0x80
	mov eax,4
	mov ebx,1
	mov ecx,[ebp]
	mov edx,1
	int 0x80
	jmp main
