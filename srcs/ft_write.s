section .text
	global ft_write
	extern ___errno_location

ft_write: ; rdi (1er param), rsi (2eme param), rdx(3eme param)
	mov rax, 1				; on set rax a 1 (correspond a write)
	syscall					; on execute write

	cmp rax, 0				; on check le retour du syscall
	js catch_error			; si <= 0 alors set le errno

	ret


catch_error:
	neg rax					; on prend la valeur absolue du code d'erreur
	mov rbp, rax
	call errno_location
	mov rbx, rax
	mov [rbx], rbp

	mov rax, -1
	ret

section .bss
	errno resd 1
