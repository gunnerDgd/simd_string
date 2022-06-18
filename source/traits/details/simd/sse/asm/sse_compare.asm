%include "sse_copy.asm"

; %1 : LHS Comparison Value
; $2 : RHS Comparison Value
; %3 : Compare Result Value
; %4 : Compare Result Masking Value

%define COMPARE_MASK 0xFFFFFFFFFFFFFFFF

%macro COMPARE_EQ 2
        shl      rax, 16
        pcmpeqd  %1 , %2
        pmovmskb ebx, %1
        or       rax, rbx
%endmacro

%macro COMPARE_GT 2
        shl      rax, 16
        pcmpgtd  %1 , %2
        pmovmskb ebx, %1
        or       rax, rbx
%endmacro

%macro COMPARE_LT 2
        shl      rax, 16
        pcmpgtd  %1 , %2
        pmovmskb ebx , %1
        or       rax, rbx
%endmacro

global __synapse_string_simd_sse_compare_eq128
global __synapse_string_simd_sse_compare_lt128
global __synapse_string_simd_sse_compare_gt128

global __synapse_string_simd_sse_compare_eq64
global __synapse_string_simd_sse_compare_lt64
global __synapse_string_simd_sse_compare_gt64

section .text

__synapse_string_simd_sse_compare_eq128:
; RCX : LHS Memory Arena
; RDX : RHS Memory Arena

    xor rax, rax
    xor rbx, rbx
    call __synapse_string_simd_sse_load_from_all
    
    COMPARE_EQ xmm0, [rdx]     
    COMPARE_EQ xmm1, [rdx + 16]
    COMPARE_EQ xmm2, [rdx + 32]
    COMPARE_EQ xmm3, [rdx + 48]

    cmp rax, COMPARE_MASK
    jnz CMP_COMPLETED_EQ128 ; If the Comparision Value is False.

    COMPARE_EQ xmm4, [rdx + 64]
    COMPARE_EQ xmm5, [rdx + 80]
    COMPARE_EQ xmm6, [rdx + 96]
    COMPARE_EQ xmm7, [rdx + 112]

CMP_COMPLETED_EQ128:
    sub rax, COMPARE_MASK
    ret

__synapse_string_simd_sse_compare_eq64:
    xor rax, rax
    xor rbx, rbx

    call __synapse_string_simd_sse_load_from_high
    call __synapse_string_simd_sse_load_from_low

    COMPARE_EQ xmm0, xmm4
    COMPARE_EQ xmm1, xmm5
    COMPARE_EQ xmm2, xmm6
    COMPARE_EQ xmm3, xmm7

    sub rax, COMPARE_MASK
    ret

__synapse_string_simd_sse_compare_gt128:
; RCX : LHS Memory Arena
; RDX : RHS Memory Arena

    xor rax, rax
    xor rbx, rbx
    call __synapse_string_simd_sse_load_from_all
    
    COMPARE_GT xmm0, [rdx]     
    COMPARE_GT xmm1, [rdx + 16]
    COMPARE_GT xmm2, [rdx + 32]
    COMPARE_GT xmm3, [rdx + 48]

    cmp rax, COMPARE_MASK
    jnz CMP_COMPLETED_GT128

    COMPARE_GT xmm4, [rdx + 64]
    COMPARE_GT xmm5, [rdx + 80]
    COMPARE_GT xmm6, [rdx + 96]
    COMPARE_GT xmm7, [rdx + 112]

CMP_COMPLETED_GT128:
    sub rax, COMPARE_MASK
    ret

__synapse_string_simd_sse_compare_gt64:
    xor rax, rax
    xor rbx, rbx
    
    call __synapse_string_simd_sse_load_from_high
    call __synapse_string_simd_sse_load_from_low

    COMPARE_GT xmm0, xmm4
    COMPARE_GT xmm1, xmm5
    COMPARE_GT xmm2, xmm6
    COMPARE_GT xmm3, xmm7

    sub rax, COMPARE_MASK
    ret

__synapse_string_simd_sse_compare_lt128:
; RCX : LHS Memory Arena
; RDX : RHS Memory Arena

    xor  rax, rax
    xor  rbx, rbx
    xchg rcx, rdx
    call __synapse_string_simd_sse_load_from_all
    
    COMPARE_LT xmm0, [rdx]      
    COMPARE_LT xmm1, [rdx + 16] 
    COMPARE_LT xmm2, [rdx + 32] 
    COMPARE_LT xmm3, [rdx + 48]

    cmp rax, COMPARE_MASK
    jnz CMP_COMPLETED_LT128

    COMPARE_LT xmm4, [rdx + 64] 
    COMPARE_LT xmm5, [rdx + 80] 
    COMPARE_LT xmm6, [rdx + 96] 
    COMPARE_LT xmm7, [rdx + 112] 

CMP_COMPLETED_LT128:
    sub rax, COMPARE_MASK
    ret

__synapse_string_simd_sse_compare_lt64:
    xor  rax, rax
    xor  rbx, rbx
    xchg rcx, rdx
    
    call __synapse_string_simd_sse_load_from_high
    call __synapse_string_simd_sse_load_from_low

    COMPARE_LT xmm0, xmm4
    COMPARE_LT xmm1, xmm5
    COMPARE_LT xmm2, xmm6
    COMPARE_LT xmm3, xmm7

    sub rax, COMPARE_MASK
    ret