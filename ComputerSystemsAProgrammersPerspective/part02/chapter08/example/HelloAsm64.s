.section .data
string:
    .ascii "hello, world\n"
string_end:
    .equi len, string_end - string

.section .text
.globl main

main
    ; write is system call 1
    movq $1, %rax
    ; arg1: stdout has descriptor 1
    movq $1, %rdi
    ; arg2: hello world string
    movq $string, %rsi
    ; arg3: string length
    movq $len, %rdx
    ; make the system call
    syscall

    ; _exit is system call 60
    movq $60, %rax
    ; arg1: exit status is 0
    movq $0, %rdi
    ; make the system call
    syscall
