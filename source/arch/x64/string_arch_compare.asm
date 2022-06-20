%include "string_arch_register.asm"

;int
;   __synapse_string_arch_sse_memcmp_nonaligned
;       (void* pLhs, void* pRhs, size_t pSize)

global __synapse_string_arch_sse_memcmp_nonaligned

section .text

__synapse_string_arch_sse_memcmp_nonaligned:
    xor rax, rax
    cmp r8, 0
    
    jg  do_compare
    mov rax, 0

    ret
do_compare:
    mov al, [rcx]
    cmp al, [rdx]

    jg do_greater
    jl do_less

    inc rcx
    inc rdx
    dec r8

    test r8, r8
    jnz  do_compare
    
    mov rax, 0
    ret
    
do_less:
    mov rax, -1
    ret
do_greater:
    mov rax, 1
    ret