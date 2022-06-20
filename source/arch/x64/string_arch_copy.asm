%include "string_arch_register.asm"

;void
;   __synapse_string_arch_sse_memcpy
;       (void* pDest, void* pSrc, size_t pRegCount)

global __synapse_string_arch_sse_memcpy

;void
;   __synapse_string_arch_sse_memcpy_nonaligned
;       (void* pDest, void* pSrc, size_t pSize)

global __synapse_string_arch_sse_memcpy_nonaligned

section .text

__synapse_string_arch_sse_memcpy:
    test r8, r8
    jnz  do_copy

    ret

do_copy:
    __synapse_string_arch_sse_load128  rdx
    __synapse_string_arch_sse_store128 rcx

    dec r8
    add rcx, 0x80
    add rdx, 0x80

    test r8, r8
    jnz  do_copy
    
    ret

__synapse_string_arch_sse_memcpy_nonaligned:
    test r8, r8
    jge  do_copy_nonaligned
    ret

do_copy_nonaligned:
    mov al   , [rdx]
    mov [rcx], al

    inc rdx
    inc rcx

    dec  r8
    test r8, r8
    
    jge do_copy_nonaligned
    ret