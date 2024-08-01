extern malloc

section .text
	global ft_strdup
	extern __errno_location

ft_strdup:	;
	mov rcx, 0						; on utilisera rcx comme index que l'on met a 0

	WHILESTR:
		mov al, BYTE[rdi+rcx*1]		; on met le char a l'index rcx dans al

		cmp al, 0					; on compare al avec 0
		je END_WHILESTR				; JAE (Jump if equal)


		inc rcx						; on incrémente rcx
		jmp WHILESTR				; on jump au debut de la boucle
	END_WHILESTR:
	inc	rax							;

	mov rax, 4						;
	imul rax, rcx					;

	mov rdi, rax					;
	call malloc						;

	cmp rax, 0						;
	js catch_error					; si malloc NULL on set le errno et on return null

	mov rcx, 0						; on met l'index a 0
	WHILESTRCPY:
		mov al, BYTE[rsi+rcx*1]		;

		cmp al, 0					; on compare al avec 0
		je END_WHILESTR				;

		mov BYTE[rax+rcx*1], al		;

		inc rcx						;
		jmp WHILESTR				;
	END_WHILESTRCPY:

	ret								;

catch_error:
	neg rax								; on prend la valeur absolue du code d'erreur

	mov rdi, rax						; on met le code derreur dans rdi

	call __errno_location wrt ..plt		; on recupere l'adresse de ernno en mode ecriture (adresse mise dans rax)

	mov [rax], rdi						; on met le code d'erreur a l'adresse de rax

	mov rax, 0							; on met rax a NULL
	ret
