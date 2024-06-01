section .text
	global ft_read
	extern __errno_location

ft_read: ; rdi (1er param), rsi (2eme param), rdx(3eme param)
	mov rax, 0							; on set rax a 0 (correspond a read)
	syscall								; on execute write

	cmp rax, 0							; on check le retour du syscall
	js catch_error						; si <= 0 alors set le errno

	ret


catch_error:
	neg rax								; on prend la valeur absolue du code d'erreur

	mov rdi, rax						; on met le code derreur dans rdi

	call __errno_location wrt ..plt		; on recupere l'adresse de ernno en mode ecriture (adresse mise dans rax)

	mov [rax], rdi						; on met le code d'erreur a l'adresse de rax

	mov rax, -1							; on met rax a -1
	ret
