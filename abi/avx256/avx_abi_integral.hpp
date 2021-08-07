#include <immintrin.h>

namespace simd {
    template <typename T>
    class abi_avx_integral
    {
    public:
        using simd_memory_t = __m256i ;
    
    public:
        static void          simd_store(simd_memory_t& l, void* r) 
        { 
            if      constexpr (sizeof(T) == 1)
                _mm256_mask_storeu_epi8 ((simd_memory_t*)r, l);
            else if constexpr (sizeof(T) == 2)
                _mm256_mask_storeu_epi16((simd_memory_t*)r, l);
            else if constexpr (sizeof(T) == 4)
                _mm256_mask_storeu_epi32((simd_memory_t*)r, l);
            else if constexpr (sizeof(T) == 8)
                _mm256_mask_storeu_epi64((simd_memory_t*)r, l);
        }
        static simd_memory_t simd_load (void* l)
        { 
            if      constexpr (sizeof(T) == 1)
                _mm256_mask_loadu_epi8 ((simd_memory_t*)r, l);
            else if constexpr (sizeof(T) == 2)
                _mm256_mask_loadu_epi16((simd_memory_t*)r, l);
            else if constexpr (sizeof(T) == 4)
                _mm256_mask_loadu_epi32((simd_memory_t*)r, l);
            else if constexpr (sizeof(T) == 8)
                _mm256_mask_loadu_epi64((simd_memory_t*)r, l);
        }

    public:
        static simd_memory_t simd_add(simd_memory_t l, simd_memory_t r)
        { 
            if      constexpr (sizeof(T) == 1)
                return _mm256_mask_add_epi8 (l, r); 
            else if constexpr (sizeof(T) == 2)
                return _mm256_mask_add_epi16(l, r);
            else if constexpr (sizeof(T) == 4)
                return _mm256_mask_add_epi32(l, r);
            else if constexpr (sizeof(T) == 8)
                return _mm256_mask_add_epi64(l, r);
        }

        static simd_memory_t simd_sub(simd_memory_t l, simd_memory_t r)
        {
            if      constexpr (sizeof(T) == 1)
                return _mm256_sub_epi8 (l, r); 
            else if constexpr (sizeof(T) == 2)
                return _mm256_sub_epi16(l, r);
            else if constexpr (sizeof(T) == 4)
                return _mm256_sub_epi32(l, r);
            else if constexpr (sizeof(T) == 8)
                return _mm256_sub_epi64(l, r);
        }

        static simd_memory_t simd_mul(simd_memory_t l, simd_memory_t r)
        {
            if      constexpr (sizeof(T) == 1)
                return _mm256_mul_epi8 (l, r); 
            else if constexpr (sizeof(T) == 2)
                return _mm256_mul_epi16(l, r);
            else if constexpr (sizeof(T) == 4)
                return _mm256_mul_epi32(l, r);
            else if constexpr (sizeof(T) == 8)
                return _mm256_mul_epi64(l, r);
        }

    public:
        static simd_memory_t simd_cmp_equal(simd_memory_t l, simd_memory_t r)
        {
            if      constexpr (sizeof(T) == 1)
                return _mm256_cmpeq_epi8 (l, r); 
            else if constexpr (sizeof(T) == 2)
                return _mm256_cmpeq_epi16(l, r);
            else if constexpr (sizeof(T) == 4)
                return _mm256_cmpeq_epi32(l, r);
            else if constexpr (sizeof(T) == 8)
                return _mm256_cmpeq_epi64(l, r);
        }
    };
}