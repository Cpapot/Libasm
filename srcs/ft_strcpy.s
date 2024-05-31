section .data
    hello db "Hello, World!", 0

section .text
	global ft_strcpy

ft_strcpy: ; rdi (1er param), rsi (2eme param)
	mov rcx, 0						; on utilisera rcx comme index que l'on met a 0


	WHILESTR:
		mov al, BYTE[rsi+rcx*1]		; on met le char a l'index rcx dans al

		CMP al, 0					; on compare al avec 0
		JE END_WHILESTR				; JAE (Jump if equal)

		mov BYTE[rdi+rcx*1], al

		INC rcx						; on incrémente rcx
		JMP WHILESTR				; on jump au debut de la boucle
	END_WHILESTR:

	mov rax, rdi					; place rdi (la dest) dans rax
	ret								; retourne rax
