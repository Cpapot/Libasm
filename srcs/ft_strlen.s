section .text
	global ft_strlen

ft_strlen: ; rdi (1er param)
	mov rcx, 0						; on utilisera rcx comme index que l'on met a 0

	WHILESTR:
		mov al, BYTE[rdi+rcx*1]		; on met le char a l'index rcx dans al

		cmp al, 0					; on compare al avec 0
		je END_WHILESTR				; JAE (Jump if equal)


		inc rcx						; on incrémente rcx
		jmp WHILESTR				; on jump au debut de la boucle
	END_WHILESTR:

	mov rax, rcx					; place rcx dans rax
	ret								; retourne rax
