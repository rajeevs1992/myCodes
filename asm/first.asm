SECTION .data
	var: db '?'
	msg: db '@ encountered!!!',10
	len: equ $-msg
SECTION .text
global main
main:
	MOV eax,3
	MOV ebx,0
	mov ecx,var
	mov edx,1
	INT 0x80
	cmp byte [var],'@'
	je main1
	jmp main

main1:
		MOV eax,4
		MOV ebx,1
		mov ecx,msg
		mov edx,len
		INT 0x80
	
