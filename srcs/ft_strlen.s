section .text
	global ft_strlen

ft_strlen:
	mov rcx, 0						; on utilisera rcx comme index que l'on met a 0
	mov rdx, rdi					; on met le premier parametre de 64 bit dans rdx

	WHILESTR:
		mov al, BYTE[rdx+rcx*1]		; on met le char a l'index rcx dans al

		CMP al, 0					; on compare al avec 0
		JE END_WHILESTR				; JAE (Jump if equal)


		INC rcx						; on incrémente rcx
		JMP WHILESTR				; on jump au debut de la boucle
	END_WHILESTR:

	mov rax, rcx					; place rcx dans rax
	ret								; retourne rax
