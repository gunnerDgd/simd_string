#include <xmmintrin.h>

#include <type_traits>
#include <iostream>

namespace simd {
    template <typename T>
    class abi_sse_floating
    {
    public:
        using simd_memory_t = __m128d ;
    
    public:
        static void          simd_store(simd_memory_t& l, void* r)
        {
            if      constexpr (std::is_same<T, float>::value)
                _mm_store_ps(l, (simd_memory_t*)r, l);
            else if constexpr (std::is_same<T, double>::value)
                _mm_store_pd(l, (simd_memory_t*)r, l);
        }

        static simd_memory_t simd_load (void* l)
        {
            if      constexpr (std::is_same<T, float>::value)
                return _mm_load_ps((simd_memory_t*)l);
            else if constexpr (std::is_same<T, double>::value)
                return _mm_load_pd((simd_memory_t*)l);
        }

    public:
        static simd_memory_t simd_add(simd_memory_t& l, simd_memory_t& r)
        { 
            if      constexpr (std::is_same<T, float>::value)
                return _mm_add_ps(l, r);
            else if constexpr (std::is_same<T, double>::value)
                return _mm_add_pd(l, r);
        }

        static simd_memory_t simd_sub(simd_memory_t& l, simd_memory_t& r)
        {
            if      constexpr (std::is_same<T, float>::value)
                return _mm_sub_ps(l, r); 
            else if constexpr (std::is_same<T, double>::value)
                return _mm_sub_pd(l, r);
        }

        static simd_memory_t simd_mul(simd_memory_t& l, simd_memory_t& r)
        {
            if      constexpr (std::is_same<T, float>::value)
                return _mm_mul_ps(l, r); 
            else if constexpr (std::is_same<T, double>::value)
                return _mm_mul_pd(l, r);
        }


    public:
        static simd_memory_t simd_cmp_equal(simd_memory_t& l, simd_memory_t& r)
        {
            if      constexpr (std::is_same<T, float>::value)
                return _mm_cmpeq_ps(l, r); 
            else if constexpr (std::is_same<T, double>::value)
                return _mm_cmpeq_pd(l, r);
        }
    };
}