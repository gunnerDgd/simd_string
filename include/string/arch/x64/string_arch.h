// ASM Exported Function
#include <stdint.h>

void
   __synapse_string_arch_sse_memcpy
       (void* pDest, void* pSrc, size_t pRegCount);

void
   __synapse_string_arch_sse_memcpy_nonaligned
       (void* pDest, void* pSrc, size_t pSize);

int
   __synapse_string_arch_sse_memcmp_nonaligned
       (void* pLhs, void* pRhs, size_t pSize);

int
   __synapse_string_arch_sse_memcmp_eq
       (void* pLhs, void* pRhs, size_t pRegCount);

int
   __synapse_string_arch_sse_memcmp_gt
       (void* pLhs, void* pRhs, size_t pRegCount);

int
   __synapse_string_arch_sse_memcmp_lt
       (void* pLhs, void* pRhs, size_t pRegCount);