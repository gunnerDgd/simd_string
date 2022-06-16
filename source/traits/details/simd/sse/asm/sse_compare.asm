%include "sse_copy.asm"

; %1 : LHS Comparison Value
; $2 : RHS Comparison Value
; %3 : Compare Result Value
; %4 : Compare Result Masking Value

%macro COMPARE_EQ 4
        pcmpeqd  %1, %2
        pmovmskb %3, %1
        and      %3, %4
%endmacro

%macro COMPARE_GT 4
        pcmpgtd  %1, %2
        pmovmskb %3, %1
        and      %3, %4
%endmacro

%macro COMPARE_LT 4
        pcmpgtd  %1, %2
        pmovmskb %3, %1
        and      %3, %4
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

    mov ebx, 0xFFFF
    call __synapse_string_simd_sse_load_from_all
    
    COMPARE_EQ xmm0, [rdx]      , eax, ebx
    COMPARE_EQ xmm1, [rdx + 16] , eax, ebx
    COMPARE_EQ xmm2, [rdx + 32] , eax, ebx
    COMPARE_EQ xmm3, [rdx + 48] , eax, ebx

    COMPARE_EQ xmm4, [rdx + 64] , eax, ebx
    COMPARE_EQ xmm5, [rdx + 80] , eax, ebx
    COMPARE_EQ xmm6, [rdx + 96] , eax, ebx
    COMPARE_EQ xmm7, [rdx + 112], eax, ebx 

    xor eax, ebx
    ret

__synapse_string_simd_sse_compare_eq64:
    mov ebx, 0xFFFF
    
    call __synapse_string_simd_sse_load_from_high
    call __synapse_string_simd_sse_load_from_low

    COMPARE_EQ xmm0, xmm4, eax, ebx
    COMPARE_EQ xmm1, xmm5, eax, ebx
    COMPARE_EQ xmm2, xmm6, eax, ebx
    COMPARE_EQ xmm3, xmm7, eax, ebx

    xor eax, ebx
    ret

__synapse_string_simd_sse_compare_gt128:
; RCX : LHS Memory Arena
; RDX : RHS Memory Arena

    mov ebx, 0xFFFF
    call __synapse_string_simd_sse_load_from_all
    
    COMPARE_GT xmm0, [rdx]     , eax, ebx
    COMPARE_GT xmm1, [rdx + 16], eax, ebx
    COMPARE_GT xmm2, [rdx + 32], eax, ebx
    COMPARE_GT xmm3, [rdx + 48], eax, ebx

    COMPARE_GT xmm4, [rdx + 64] , eax, ebx
    COMPARE_GT xmm5, [rdx + 80] , eax, ebx
    COMPARE_GT xmm6, [rdx + 96] , eax, ebx
    COMPARE_GT xmm7, [rdx + 112], eax, ebx 

    xor eax, ebx
    ret

__synapse_string_simd_sse_compare_gt64:
    mov ebx, 0xFFFF
    
    call __synapse_string_simd_sse_load_from_high
    call __synapse_string_simd_sse_load_from_low

    COMPARE_GT xmm0, xmm4, eax, ebx
    COMPARE_GT xmm1, xmm5, eax, ebx
    COMPARE_GT xmm2, xmm6, eax, ebx
    COMPARE_GT xmm3, xmm7, eax, ebx

    xor eax, ebx
    ret

__synapse_string_simd_sse_compare_lt128:
; RCX : LHS Memory Arena
; RDX : RHS Memory Arena

    mov  ebx, 0xFFFF
    xchg rcx, rdx
    call __synapse_string_simd_sse_load_from_all
    
    COMPARE_LT xmm0, [rdx]      , eax, ebx
    COMPARE_LT xmm1, [rdx + 16] , eax, ebx
    COMPARE_LT xmm2, [rdx + 32] , eax, ebx
    COMPARE_LT xmm3, [rdx + 48] , eax, ebx

    COMPARE_LT xmm4, [rdx + 64] , eax, ebx
    COMPARE_LT xmm5, [rdx + 80] , eax, ebx
    COMPARE_LT xmm6, [rdx + 96] , eax, ebx
    COMPARE_LT xmm7, [rdx + 112], eax, ebx 

    xor eax, ebx
    ret

__synapse_string_simd_sse_compare_lt64:
    mov  ebx, 0xFFFF
    xchg rcx, rdx
    
    call __synapse_string_simd_sse_load_from_high
    call __synapse_string_simd_sse_load_from_low

    COMPARE_LT xmm0, xmm4, eax, ebx
    COMPARE_LT xmm1, xmm5, eax, ebx
    COMPARE_LT xmm2, xmm6, eax, ebx
    COMPARE_LT xmm3, xmm7, eax, ebx

    xor eax, ebx
    ret