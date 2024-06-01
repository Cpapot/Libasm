section .text
	global ft_strcmp

ft_strcmp: ; rdi (1er param), rsi (2eme param)
	mov rcx, 0						; on utilisera rcx comme index que l'on met a 0


	WHILESTR:
		mov al, BYTE[rdi+rcx*1]		; on met le char de s1 a l'index rcx dans al
		mov bl, BYTE[rsi+rcx*1]		; on met le char de s2 a l'index rcx dans al

		cmp al, 0					; on compare al avec 0
		je END_WHILESTR				; JE (Jump if equal)
		cmp bl, 0					; on compare bl avec 0
		je END_WHILESTR				; JE (Jump if equal)

		cmp bl, al					; on compare s1[i] avec s2[i]
		jne END_WHILESTR			; JNE (Jump if not equal)

		inc rcx						; on incrémente rcx
		jmp WHILESTR				; on jump au debut de la boucle
	END_WHILESTR:

	sub al, bl						; s1[i] - s2[i]

	movsx rax, al					; place al (le resultat de la soustraction) dans rax (sx convertit proprement le char de 8 bits à 64 bits)
	ret								; retourne rax
