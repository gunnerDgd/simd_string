#include <simd/abi/sse/sse_abi.hpp>

namespace simd {
namespace abi  {

    template <> class sse<float> ;
    template <> class sse<double>;
}
}

template <>
class simd::abi::sse<float>
{
public:
    using  abi_t = __m128;

    static void  copy_to  (abi_t a, uint8_t* m) {        _mm_store_ps((abi_t*)m, a); }
    static abi_t copy_from(uint8_t* m)          { return _mm_load_ps ((abi_t*)m)    ; }
    
    static abi_t add   (abi_t l, abi_t r) { return _mm_add_ps(l, r); }
    static abi_t sub   (abi_t l, abi_t r) { return _mm_sub_ps(l, r); }
    static abi_t mul   (abi_t l, abi_t r) { return _mm_mul_ps(l, r); }
    
    static abi_t cmp_eq(abi_t l, abi_t r) { return _mm_cmpeq_ps(l, r); }
    static abi_t cmp_lt(abi_t l, abi_t r) { return _mm_cmplt_ps(l, r); }
    static abi_t cmp_gt(abi_t l, abi_t r) { return _mm_cmpgt_ps(l, r); }
};

template <>
class simd::abi::sse<double>
{
public:
    using  abi_t = __m128d;

    static void  copy_to  (abi_t a, uint8_t* m) {        _mm_store_pd((abi_t*)m, a); }
    static abi_t copy_from(uint8_t* m)          { return _mm_load_pd ((abi_t*)m)    ; }
    
    static abi_t add   (abi_t l, abi_t r) { return _mm_add_pd(l, r); }
    static abi_t sub   (abi_t l, abi_t r) { return _mm_sub_pd(l, r); }
    static abi_t mul   (abi_t l, abi_t r) { return _mm_mul_pd(l, r); }
    
    static abi_t cmp_eq(abi_t l, abi_t r) { return _mm_cmpeq_pd(l, r); }
    static abi_t cmp_lt(abi_t l, abi_t r) { return _mm_cmplt_pd(l, r); }
    static abi_t cmp_gt(abi_t l, abi_t r) { return _mm_cmpgt_pd(l, r); }
};