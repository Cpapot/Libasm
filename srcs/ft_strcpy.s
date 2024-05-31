section .data
    hello db "Hello, World!", 0

section .text
	global ft_strcpy

ft_strcpy:
    ; Write "Hello, World!" to stdout
    mov rax, 1          ; syscall number for sys_write
    mov rdi, 1          ; file descriptor 1 (stdout)
    mov rsi, hello      ; pointer to the message
    mov rdx, 13         ; length of the message
    syscall             ; invoke the system call
	ret					;
