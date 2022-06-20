global __synapse_string_alloc_bucket_copy

; void
; __synapse_string_alloc_sse_copy
;   (void* pDest, void* pSrc, size_t pBucketCount)

__synapse_string_alloc_sse_copy:
    cmp r8, 0
    jnz start_copy
    ret
do_copy:
    movdqa xmm0, [rdx]
    movdqa xmm1, [rdx + 0x10]
    movdqa xmm2, [rdx + 0x20]
    movdqa xmm3, [rdx + 0x30]

    movdqa xmm4, [rdx + 0x40]
    movdqa xmm5, [rdx + 0x50]
    movdqa xmm6, [rdx + 0x60]
    movdqa xmm7, [rdx + 0x70]

    movdqa [rcx]       , xmm0
    movdqa [rcx + 0x10], xmm1
    movdqa [rcx + 0x20], xmm2
    movdqa [rcx + 0x30], xmm3

    movdqa [rcx + 0x40], xmm4
    movdqa [rcx + 0x50], xmm5
    movdqa [rcx + 0x60], xmm6
    movdqa [rcx + 0x70], xmm7

    dec r8
    cmp r8, 0
    jnz do_copy
    ret

start_copy:
    cmp r8, 0
    jnz do_copy