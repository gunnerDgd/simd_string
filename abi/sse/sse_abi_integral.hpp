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

    static void  copy_to  (abi_t& a, uint8_t* m) {        _mm_store_si128((abi_t*)m, a); }
    static abi_t copy_from(uint8_t* m)           { return _mm_load_si128 ((abi_t*)m)   ; }
    
    static abi_t add   (abi_t& l, abi_t& r)       { return _mm_adds_epi8(l, r); }
    static abi_t sub   (abi_t& l, abi_t& r)       { return _mm_subs_epi8(l, r); }
    static abi_t mul   (abi_t& l, abi_t& r);
    
    static abi_t cmp_eq(abi_t& l, abi_t& r)       { return _mm_cmpeq_epi8(l, r); }
    static abi_t cmp_lt(abi_t& l, abi_t& r)       { return _mm_cmplt_epi8(l, r); }
    static abi_t cmp_gt(abi_t& l, abi_t& r)       { return _mm_cmpgt_epi8(l, r); }
};

simd::abi::sse<uint8_t>::abi_t simd::abi::sse<uint8_t>::mul(abi_t& l, abi_t& r)
{
    __m128i l_hi = _mm_unpackhi_epi8(l, _mm_setzero_si128()),
            l_lo = _mm_unpacklo_epi8(l, _mm_setzero_si128()),

            r_hi = _mm_unpackhi_epi8(r, _mm_setzero_si128()),
            r_lo = _mm_unpackhi_epi8(r, _mm_setzero_si128());

    l_hi = _mm_mullo_epi16 (l_hi, r_hi);
    l_lo = _mm_mullo_epi16 (l_lo, r_lo);

    return _mm_packus_epi16(l_lo, l_hi);
}

template <>
class simd::abi::sse<uint16_t>
{
public:
    using  abi_t = __m128i;

    static void  copy_to  (abi_t& a, uint16_t* m) {       _mm_store_si128((abi_t*)m, a); }
    static abi_t copy_from(uint16_t* m)          { return _mm_load_si128 ((abi_t*)m)   ; }
    
    static abi_t add   (abi_t& l, abi_t& r)       { return _mm_adds_epu16(l, r); }
    static abi_t sub   (abi_t& l, abi_t& r)       { return _mm_subs_epu16(l, r); }
    static abi_t mul   (abi_t& l, abi_t& r);
    
    static abi_t cmp_eq(abi_t& l, abi_t& r)       { return _mm_cmpeq_epi16(l, r); }
    static abi_t cmp_lt(abi_t& l, abi_t& r)       { return _mm_cmplt_epi16(l, r); }
    static abi_t cmp_gt(abi_t& l, abi_t& r)       { return _mm_cmpgt_epi16(l, r); }
};

simd::abi::sse<uint16_t>::abi_t simd::abi::sse<uint16_t>::mul(abi_t& l, abi_t& r)
{
    __m128i l_hi = _mm_unpackhi_epi16(l, _mm_setzero_si128()),
            l_lo = _mm_unpacklo_epi16(l, _mm_setzero_si128()),

            r_hi = _mm_unpackhi_epi16(r, _mm_setzero_si128()),
            r_lo = _mm_unpacklo_epi16(r, _mm_setzero_si128());

    l_hi = _mm_mullo_epi32 (l_hi, r_hi);
    l_lo = _mm_mullo_epi32 (l_lo, r_lo);

    return _mm_packus_epi32(l_lo, l_hi);
}

template <>
class simd::abi::sse<uint32_t>
{
public:
    using  abi_t = __m128i;

    static void   copy_to  (abi_t& a, uint32_t* m) {        _mm_store_si128((abi_t*)m, a); }
    static abi_t copy_from(uint32_t* m)            { return _mm_load_si128 ((abi_t*)m)   ; }
    
    static abi_t add   (abi_t& l, abi_t& r)       { return _mm_add_epi32  (l, r); }
    static abi_t sub   (abi_t& l, abi_t& r)       { return _mm_sub_epi32  (l, r); }
    static abi_t mul   (abi_t& l, abi_t& r)       { return _mm_mullo_epi32(l, r); }
    
    static abi_t cmp_eq(abi_t& l, abi_t& r)       { return _mm_cmpeq_epi32(l, r); }
    static abi_t cmp_lt(abi_t& l, abi_t& r)       { return _mm_cmplt_epi32(l, r); }
    static abi_t cmp_gt(abi_t& l, abi_t& r)       { return _mm_cmpgt_epi32(l, r); }
};

template <>
class simd::abi::sse<int8_t>
{
public:
    using  abi_t = __m128i;

    static void  copy_to  (abi_t& a, int8_t* m) {        _mm_store_si128((abi_t*)m, a); }
    static abi_t copy_from(int8_t* m)           { return _mm_load_si128 ((abi_t*)m)   ; }
    
    static abi_t add   (abi_t& l, abi_t& r)       { return _mm_add_epi8(l, r); }
    static abi_t sub   (abi_t& l, abi_t& r)       { return _mm_sub_epi8(l, r); }
    static abi_t mul   (abi_t& l, abi_t& r);
    
    static abi_t cmp_eq(abi_t& l, abi_t& r)       { return _mm_cmpeq_epi8(l, r); }
    static abi_t cmp_lt(abi_t& l, abi_t& r)       { return _mm_cmplt_epi8(l, r); }
    static abi_t cmp_gt(abi_t& l, abi_t& r)       { return _mm_cmpgt_epi8(l, r); }
};

simd::abi::sse<int8_t>::abi_t simd::abi::sse<int8_t>::mul(abi_t& l, abi_t& r)
{
    __m128i l_hi = _mm_unpackhi_epi8(l, _mm_setzero_si128()),
            l_lo = _mm_unpacklo_epi8(l, _mm_setzero_si128()),

            r_hi = _mm_unpackhi_epi8(r, _mm_setzero_si128()),
            r_lo = _mm_unpacklo_epi8(r, _mm_setzero_si128());

    l_hi = _mm_mullo_epi16 (l_hi, r_hi);
    l_lo = _mm_mullo_epi16 (l_lo, r_lo);

    return _mm_packus_epi16(l_lo, l_hi);
}

template <>
class simd::abi::sse<int16_t>
{
public:
    using  abi_t = __m128i;

    static void  copy_to  (abi_t& a, int16_t* m) {       _mm_store_si128((abi_t*)m, a); }
    static abi_t copy_from(int16_t* m)          { return _mm_load_si128((abi_t*)m)    ; }
    
    static abi_t add   (abi_t& l, abi_t& r) { return _mm_add_epi16(l, r); }
    static abi_t sub   (abi_t& l, abi_t& r) { return _mm_sub_epi16(l, r); }
    static abi_t mul   (abi_t& l, abi_t& r);
    
    static abi_t cmp_eq(abi_t& l, abi_t& r) { return _mm_cmpeq_epi16(l, r); }
    static abi_t cmp_lt(abi_t& l, abi_t& r) { return _mm_cmplt_epi16(l, r); }
    static abi_t cmp_gt(abi_t& l, abi_t& r) { return _mm_cmpgt_epi16(l, r); }
};

simd::abi::sse<int16_t>::abi_t simd::abi::sse<int16_t>::mul(abi_t& l, abi_t& r)
{
    __m128i l_hi = _mm_unpackhi_epi16(l, _mm_setzero_si128()),
            l_lo = _mm_unpacklo_epi16(l, _mm_setzero_si128()),

            r_hi = _mm_unpackhi_epi16(r, _mm_setzero_si128()),
            r_lo = _mm_unpacklo_epi16(r, _mm_setzero_si128());

    l_hi         = _mm_mullo_epi32 (l_hi, r_hi);
    l_lo         = _mm_mullo_epi32 (l_lo, r_lo);

    return         _mm_packus_epi32(l_lo, l_hi);
}

template <>
class simd::abi::sse<int32_t>
{
public:
    using  abi_t = __m128i;

    static void  copy_to  (abi_t& a, int32_t* m) {       _mm_store_si128((abi_t*)m, a); }
    static abi_t copy_from(int32_t* m)          { return _mm_load_si128 ((abi_t*)m)   ; }
    
    static abi_t add   (abi_t& l, abi_t& r) { return _mm_add_epi32  (l, r); }
    static abi_t sub   (abi_t& l, abi_t& r) { return _mm_sub_epi32  (l, r); }
    static abi_t mul   (abi_t& l, abi_t& r) { return _mm_mullo_epi32(l, r); }
    
    static abi_t cmp_eq(abi_t& l, abi_t& r) { return _mm_cmpeq_epi32(l, r); }
    static abi_t cmp_lt(abi_t& l, abi_t& r) { return _mm_cmplt_epi32(l, r); }
    static abi_t cmp_gt(abi_t& l, abi_t& r) { return _mm_cmpgt_epi32(l, r); }
};