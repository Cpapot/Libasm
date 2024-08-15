section .text
	extern malloc
	extern ft_strlen
	extern ft_strcpy
	global ft_strdup
	extern __errno_location

ft_strdup:	;
	cmp rdi, 0x0					;
	jz catch_error					;

	push rbp						;
	mov rbp, rsp					;
	mov r12, rdi					;

	call ft_strlen					;
	inc rax							;

	mov rdi, rax					;
	call malloc						;

	test rax, rax					;
	jz catch_error					; si malloc NULL on set le errno et on return null

	mov rdi, rax					;
	mov rsi, r12					;

	call ft_strcpy					;
	pop rbp							;

	ret								;

catch_error:
	xor rax, rax					;
	pop rbp							;
	ret								;

