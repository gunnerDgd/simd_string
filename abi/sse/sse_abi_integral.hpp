#include <simd/abi/sse/sse_abi.hpp>

namespace simd {
namespace abi  {

    template <> class sse<uint8_t> ;
    template <> class sse<uint16_t>;
    template <> class sse<uint32_t>;

    template <> class sse<int8_t>  ;
    template <> class sse<int16_t> ;
    template <> class sse<int32_t> ;
}
}

template <>
class simd::abi::sse<uint8_t>
{
public:
    using  abi_t = __m128i;

    static void  copy_to  (abi_t a, uint8_t* m) {        _mm_store_si128((abi_t*)m, a); }
    static abi_t copy_from(uint8_t* m)          { return _mm_load_si128((abi_t*)m)    ; }
    
    static abi_t add   (abi_t l, abi_t r) { return _mm_add_epi8(l, r); }
    static abi_t sub   (abi_t l, abi_t r) { return _mm_sub_epi8(l, r); }
    static abi_t mul   (abi_t l, abi_t r) { return _mm_mul_epu8(l, r); }
    
    static abi_t cmp_eq(abi_t l, abi_t r) { return _mm_cmpeq_epu8(l, r); }
    static abi_t cmp_lt(abi_t l, abi_t r) { return _mm_cmplt_epu8(l, r); }
    static abi_t cmp_gt(abi_t l, abi_t r) { return _mm_cmpgt_epu8(l, r); }
};

template <>
class simd::abi::sse<uint16_t>
{
public:
    using  abi_t = __m128i;

    static void  copy_to  (abi_t a, uint8_t* m) {        _mm_store_si128((abi_t*)m, a); }
    static abi_t copy_from(uint8_t* m)          { return _mm_load_si128((abi_t*)m)    ; }
    
    static abi_t add   (abi_t l, abi_t r) { return _mm_add_epu16(l, r); }
    static abi_t sub   (abi_t l, abi_t r) { return _mm_sub_epu16(l, r); }
    static abi_t mul   (abi_t l, abi_t r) { return _mm_mul_epu16(l, r); }
    
    static abi_t cmp_eq(abi_t l, abi_t r) { return _mm_cmpeq_epu16(l, r); }
    static abi_t cmp_lt(abi_t l, abi_t r) { return _mm_cmplt_epu16(l, r); }
    static abi_t cmp_gt(abi_t l, abi_t r) { return _mm_cmpgt_epu16(l, r); }
};

template <>
class simd::abi::sse<uint32_t>
{
public:
    using  abi_t = __m128i;

    static void  copy_to  (abi_t a, uint8_t* m) {        _mm_store_si128((abi_t*)m, a); }
    static abi_t copy_from(uint8_t* m)          { return _mm_load_si128((abi_t*)m)    ; }
    
    static abi_t add   (abi_t l, abi_t r) { return _mm_add_epu32(l, r); }
    static abi_t sub   (abi_t l, abi_t r) { return _mm_sub_epu32(l, r); }
    static abi_t mul   (abi_t l, abi_t r) { return _mm_mul_mul32(l, r); }
    
    static abi_t cmp_eq(abi_t l, abi_t r) { return _mm_cmpeq_epu32(l, r); }
    static abi_t cmp_lt(abi_t l, abi_t r) { return _mm_cmplt_epu32(l, r); }
    static abi_t cmp_gt(abi_t l, abi_t r) { return _mm_cmpgt_epu32(l, r); }
};

template <>
class simd::abi::sse<int8_t>
{
public:
    using  abi_t = __m128i;

    static void  copy_to  (abi_t a, uint8_t* m) {        _mm_store_si128((abi_t*)m, a); }
    static abi_t copy_from(uint8_t* m)          { return _mm_load_si128((abi_t*)m)    ; }
    
    static abi_t add   (abi_t l, abi_t r) { return _mm_add_epi8(l, r); }
    static abi_t sub   (abi_t l, abi_t r) { return _mm_sub_epi8(l, r); }
    static abi_t mul   (abi_t l, abi_t r) { return _mm_mul_epi8(l, r); }
    
    static abi_t cmp_eq(abi_t l, abi_t r) { return _mm_cmpeq_epi8(l, r); }
    static abi_t cmp_lt(abi_t l, abi_t r) { return _mm_cmplt_epi8(l, r); }
    static abi_t cmp_gt(abi_t l, abi_t r) { return _mm_cmpgt_epi8(l, r); }
};

template <>
class simd::abi::sse<int16_t>
{
public:
    using  abi_t = __m128i;

    static void  copy_to  (abi_t a, uint8_t* m) {        _mm_store_si128((abi_t*)m, a); }
    static abi_t copy_from(uint8_t* m)          { return _mm_load_si128((abi_t*)m)    ; }
    
    static abi_t add   (abi_t l, abi_t r) { return _mm_add_epi16(l, r); }
    static abi_t sub   (abi_t l, abi_t r) { return _mm_sub_epi16(l, r); }
    static abi_t mul   (abi_t l, abi_t r) { return _mm_mul_epi16(l, r); }
    
    static abi_t cmp_eq(abi_t l, abi_t r) { return _mm_cmpeq_epi16(l, r); }
    static abi_t cmp_lt(abi_t l, abi_t r) { return _mm_cmplt_epi16(l, r); }
    static abi_t cmp_gt(abi_t l, abi_t r) { return _mm_cmpgt_epi16(l, r); }
};

template <>
class simd::abi::sse<int32_t>
{
public:
    using  abi_t = __m128i;

    static void  copy_to  (abi_t a, uint8_t* m) {        _mm_store_si128((abi_t*)m, a); }
    static abi_t copy_from(uint8_t* m)          { return _mm_load_si128((abi_t*)m)    ; }
    
    static abi_t add   (abi_t l, abi_t r) { return _mm_add_epi32(l, r); }
    static abi_t sub   (abi_t l, abi_t r) { return _mm_sub_epi32(l, r); }
    static abi_t mul   (abi_t l, abi_t r) { return _mm_mul_epi32(l, r); }
    
    static abi_t cmp_eq(abi_t l, abi_t r) { return _mm_cmpeq_epi32(l, r); }
    static abi_t cmp_lt(abi_t l, abi_t r) { return _mm_cmplt_epi32(l, r); }
    static abi_t cmp_gt(abi_t l, abi_t r) { return _mm_cmpgt_epi32(l, r); }
};