#include <xmmintrin.h>

namespace simd {
    template <typename T>
    class abi_sse_integral
    {
    public:
        using simd_memory_t = __m128i ;
    
    public:
        static void          simd_store(simd_memory_t& l, void* r) { _mm_store_si128      ((simd_memory_t*)r, l); }
        static simd_memory_t simd_load (void* l)                   { return _mm_load_si128((simd_memory_t*)l)   ; }

    public:
        static simd_memory_t simd_add(simd_memory_t l, simd_memory_t r)
        { 
            if      constexpr (sizeof(T) == 1)
                return _mm_add_epi8 (l, r); 
            else if constexpr (sizeof(T) == 2)
                return _mm_add_epi16(l, r);
            else if constexpr (sizeof(T) == 4)
                return _mm_add_epi32(l, r);
        }

        static simd_memory_t simd_sub(simd_memory_t l, simd_memory_t r)
        {
            if      constexpr (sizeof(T) == 1)
                return _mm_sub_epi8 (l, r); 
            else if constexpr (sizeof(T) == 2)
                return _mm_sub_epi16(l, r);
            else if constexpr (sizeof(T) == 4)
                return _mm_sub_epi32(l, r);
        }

        static simd_memory_t simd_mul(simd_memory_t l, simd_memory_t r)
        {
            if      constexpr (sizeof(T) == 1)
                return _mm_mul_epi8 (l, r); 
            else if constexpr (sizeof(T) == 2)
                return _mm_mul_epi16(l, r);
            else if constexpr (sizeof(T) == 4)
                return _mm_mul_epi32(l, r);
        }

    public:
        static simd_memory_t simd_cmp_equal(simd_memory_t l, simd_memory_t r)
        {
            if      constexpr (sizeof(T) == 1)
                return _mm_cmpeq_epi8 (l, r); 
            else if constexpr (sizeof(T) == 2)
                return _mm_cmpeq_epi16(l, r);
            else if constexpr (sizeof(T) == 4)
                return _mm_cmpeq_epi32(l, r);
        }
    };
}