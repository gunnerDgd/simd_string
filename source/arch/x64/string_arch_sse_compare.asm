%include "string_arch_register.asm"

;int
;   __synapse_string_arch_sse_memcmp_eq
;       (void* pLhs, void* pRhs, size_t pRegCount)
global __synapse_string_arch_sse_memcmp_eq

;int
;   __synapse_string_arch_sse_memcmp_gt
;       (void* pLhs, void* pRhs, size_t pRegCount)
global __synapse_string_arch_sse_memcmp_gt

;int
;   __synapse_string_arch_sse_memcmp_lt
;       (void* pLhs, void* pRhs, size_t pRegCount)
global __synapse_string_arch_sse_memcmp_lt

section .text

__synapse_string_arch_sse_memcmp_eq:
do_sse_memcmp_eq:
    test r8, r8
    jz   end_sse_memcmp_eq_true

    prefetcht0 [rcx + 0x40]
    prefetcht0 [rdx + 0x40]

    __synapse_string_arch_sse_compare_eq128
    jne end_sse_memcmp_eq_false

    add rcx, 0x40
    add rdx, 0x40
    dec r8
    
    jmp do_sse_memcmp_eq
    
end_sse_memcmp_eq_true:
    mov rax, 1
    ret

end_sse_memcmp_eq_false:
    mov rax, 0
    ret

__synapse_string_arch_sse_memcmp_gt:
do_sse_memcmp_gt:
    test r8, r8
    jz   end_sse_memcmp_gt_true

    prefetcht0 [rcx + 0x40]
    prefetcht0 [rdx + 0x40]

    __synapse_string_arch_sse_compare_gt128

    add rcx, 0x40
    add rdx, 0x40
    dec r8
    
    je  do_sse_memcmp_gt
    jmp end_sse_memcmp_gt_false
    
end_sse_memcmp_gt_true:
    mov rax, 1
    ret

end_sse_memcmp_gt_false:
    mov rax, 0
    ret

__synapse_string_arch_sse_memcmp_lt:
do_sse_memcmp_lt:
    test r8, r8
    jz   end_sse_memcmp_lt_true

    prefetcht0 [rcx + 0x40]
    prefetcht0 [rdx + 0x40]

    __synapse_string_arch_sse_compare_lt128

    add rcx, 0x40
    add rdx, 0x40
    dec r8
    
    je  do_sse_memcmp_lt
    jmp end_sse_memcmp_lt_false
    
end_sse_memcmp_lt_true:
    mov rax, 1
    ret

end_sse_memcmp_lt_false:
    mov rax, 0
    ret