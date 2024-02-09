; 101-hello_holberton.asm
section .data
	msg db 'Hello, Holberton', 0x0A

section .text
	global main
	extern printf

main:
	; printf(msg)
	mov rdi, msg
	xor rax, rax
	call printf

	; return 0
	xor rax, rax
	ret
