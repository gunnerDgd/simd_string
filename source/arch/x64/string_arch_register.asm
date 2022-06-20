; RCX : Pointer Of Memory Which Contains Desired Data
%macro __synapse_string_arch_sse_load64_high 1
    movdqu xmm4, [%1]
    movdqu xmm5, [%1 + 16]
    movdqu xmm6, [%1 + 32]
    movdqu xmm7, [%1 + 48]
%endmacro

; RCX : Pointer Of Memory Which Contains Desired Data
%macro __synapse_string_arch_sse_load64_low 1
    movdqu xmm0, [%1]
    movdqu xmm1, [%1 + 16]
    movdqu xmm2, [%1 + 32]
    movdqu xmm3, [%1 + 48]
%endmacro

%macro __synapse_string_arch_sse_load128 1
    __synapse_string_arch_sse_load64_high %1
    __synapse_string_arch_sse_load64_low  %1
%endmacro

; RCX : Pointer Of Memory Which Contains Desired Data
%macro __synapse_string_arch_sse_store64_high 1
    movdqu [%1]     , xmm4
    movdqu [%1 + 16], xmm5
    movdqu [%1 + 32], xmm6
    movdqu [%1 + 48], xmm7
%endmacro

; RCX : Pointer Of Memory Which Contains Desired Data
%macro __synapse_string_arch_sse_store64_low 1
    movdqu [%1]     , xmm0
    movdqu [%1 + 16], xmm1
    movdqu [%1 + 32], xmm2
    movdqu [%1 + 48], xmm3
%endmacro

%macro __synapse_string_arch_sse_store128 1
    __synapse_string_arch_sse_store64_high %1
    __synapse_string_arch_sse_store64_low  %1
%endmacro

; macro __synapse_string_arch_sse_compare_eq
; %1 : Left Comparison Value
; %2 : Right Comparison Value

%macro __synapse_string_arch_sse_compare_eq 2
        xor      rbx, rbx
        sal      rax, 16
        pcmpeqd  %1 , %2
        pmovmskb ebx, %1
        or       rax, rbx
%endmacro

; macro __synapse_string_arch_sse_compare_gt
; %1 : Left Comparison Value
; %2 : Right Comparison Value

%macro __synapse_string_arch_sse_compare_gt 2
        xor      rbx, rbx
        sal      rax, 16
        pcmpgtd  %1 , %2
        pmovmskb ebx, %1
        or       rax, rbx
%endmacro

; macro __synapse_string_arch_sse_compare_lt
; %1 : Left Comparison Value
; %2 : Right Comparison Value

%macro __synapse_string_arch_sse_compare_lt 2
        xor      rbx, rbx
        sal      rax, 16
        pcmpgtd  %1 , %2
        pmovmskb ebx , %1
        or       rax, rbx
%endmacro

%define __synapse_string_arch_sse_compare_mask -1

; macro __synapse_string_arch_sse_compare_eq128
; %1 : Left Comparison Value
; %2 : Right Comparison Value

%macro __synapse_string_arch_sse_compare_eq128 0
    xor rax, rax

    __synapse_string_arch_sse_load64_high rcx
    __synapse_string_arch_sse_load64_low  rdx

    __synapse_string_arch_sse_compare_eq xmm0, xmm4
    __synapse_string_arch_sse_compare_eq xmm1, xmm5
    __synapse_string_arch_sse_compare_eq xmm2, xmm6
    __synapse_string_arch_sse_compare_eq xmm3, xmm7

    cmp rax, __synapse_string_arch_sse_compare_mask
%endmacro

; macro __synapse_string_arch_sse_compare_gt128
; %1 : Left Comparison Value
; %2 : Right Comparison Value

%macro __synapse_string_arch_sse_compare_gt128 0
    xor rax, rax

    __synapse_string_arch_sse_load64_high rcx
    __synapse_string_arch_sse_load64_low  rdx

    __synapse_string_arch_sse_compare_gt xmm0, xmm4
    __synapse_string_arch_sse_compare_gt xmm1, xmm5
    __synapse_string_arch_sse_compare_gt xmm2, xmm6
    __synapse_string_arch_sse_compare_gt xmm3, xmm7

    cmp rax, __synapse_string_arch_sse_compare_mask
%endmacro

; macro __synapse_string_arch_sse_compare_lt128
; %1 : Left Comparison Value
; %2 : Right Comparison Value

%macro __synapse_string_arch_sse_compare_lt128 0
    xor rax, rax

    __synapse_string_arch_sse_load64_high rdx
    __synapse_string_arch_sse_load64_low  rcx

    __synapse_string_arch_sse_compare_lt xmm0, xmm4
    __synapse_string_arch_sse_compare_lt xmm1, xmm5
    __synapse_string_arch_sse_compare_lt xmm2, xmm6
    __synapse_string_arch_sse_compare_lt xmm3, xmm7

    cmp rax, __synapse_string_arch_sse_compare_mask
%endmacro