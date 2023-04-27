section .data
    msg: db "Hello, Holberton", 10

section .text
    global main

    extern printf

main:
    push msg
    push qword 0
    mov rsi, rsp
    mov rdi, format
    xor eax, eax
    call printf
    add rsp, 16
    xor eax, eax
    ret

format:
    db "%s", 10, 0

