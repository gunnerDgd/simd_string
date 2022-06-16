global __synapse_string_simd_sse_load_from
global __synapse_string_simd_sse_store_to

global __synapse_string_simd_sse_load_from_all
global __synapse_string_simd_sse_store_to_all

global __synapse_string_simd_sse_load_from_high
global __synapse_string_simd_sse_load_from_low

global __synapse_string_simd_sse_store_to_high
global __synapse_string_simd_sse_store_to_low

section .text

__synapse_string_simd_sse_load_from_high:
; RCX : Pointer Of Memory Which Contains Desired Data
    movdqu xmm4, [rcx]
    movdqu xmm5, [rcx + 16]
    movdqu xmm6, [rcx + 32]
    movdqu xmm7, [rcx + 48]

    ret

__synapse_string_simd_sse_load_from_low:
; RCX : Pointer Of Memory Which Contains Desired Data
    movdqu xmm0, [rcx]
    movdqu xmm1, [rcx + 16]
    movdqu xmm2, [rcx + 32]
    movdqu xmm3, [rcx + 48]

    ret

__synapse_string_simd_sse_store_to_high:
; RCX : Pointer Of Memory Which Contains Memory Area
    movdqu [rcx]     , xmm4
    movdqu [rcx + 16], xmm5
    movdqu [rcx + 32], xmm6
    movdqu [rcx + 48], xmm7

    ret

__synapse_string_simd_sse_store_to_low:
; RCX : Pointer Of Memory Which Contains Memory Area
    movdqu [rcx]     , xmm0
    movdqu [rcx + 16], xmm1
    movdqu [rcx + 32], xmm2
    movdqu [rcx + 48], xmm3

    ret

__synapse_string_simd_sse_load_from_all:
    movdqu xmm0, [rcx]
    movdqu xmm1, [rcx + 16]
    movdqu xmm2, [rcx + 32]
    movdqu xmm3, [rcx + 48]
    movdqu xmm4, [rcx + 64]
    movdqu xmm5, [rcx + 80]
    movdqu xmm6, [rcx + 96]
    movdqu xmm7, [rcx + 112]

    ret

__synapse_string_simd_sse_store_to_all:
    movdqu [rcx]      , xmm0
    movdqu [rcx + 16] , xmm1
    movdqu [rcx + 32] , xmm2
    movdqu [rcx + 48] , xmm3
    movdqu [rcx + 64] , xmm4
    movdqu [rcx + 80] , xmm5
    movdqu [rcx + 96] , xmm6
    movdqu [rcx + 112], xmm7

    ret

__synapse_string_simd_sse_load_from:
; RCX : LHS Pointer
; RDX : RHS Pointer
    call __synapse_string_simd_sse_load_from_high
    mov rcx, rdx
    call __synapse_string_simd_sse_load_from_low
    ret

__synapse_string_simd_sse_store_to:
    call __synapse_string_simd_sse_store_to_high
    mov rcx, rdx
    call __synapse_string_simd_sse_store_to_low
    ret