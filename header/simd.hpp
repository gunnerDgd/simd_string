#ifdef CPU_SIMD_ENABLE_AVX
#include <simd/abi/avx256/avx_abi_integral.hpp>
#else
#include <simd/abi/sse/sse_abi_integral.hpp>
#include <simd/abi/sse/sse_abi_floating.hpp>
#endif

#include <type_traits>

namespace simd {
    #ifdef CPU_SIMD_ENABLE_AVX
    template <typename T, typename Abi = abi_avx_integral<T>>
    #else
    template <typename T, typename Abi = abi::sse<T>>
    #endif
    class simd_base
    {
    protected:
        typename Abi::abi_t simd_base_memory;

    public:
        simd_base()                                                              { }
        simd_base(T* m)                    : simd_base_memory(Abi::copy_from(m)) { }
        simd_base(typename Abi::abi_t&& m) : simd_base_memory(m)                 { }
        simd_base(typename Abi::abi_t&  m) : simd_base_memory(m)                 { }

    public:
        void copy_to  (T* m) { Abi::copy_to(simd_base_memory, m)   ; }
        void copy_from(T* m) { simd_base_memory = Abi::copy_from(m); }

    public:
        typename Abi::abi_t& native_simd_type() { return simd_base_memory; }
        
        simd_base<T, Abi> operator+(simd_base<T, Abi>& r) noexcept { return simd_base<T, Abi>(Abi::add(simd_base_memory, r.native_simd_type())); }
        simd_base<T, Abi> operator-(simd_base<T, Abi>& r) noexcept { return simd_base<T, Abi>(Abi::sub(simd_base_memory, r.native_simd_type())); }
        simd_base<T, Abi> operator*(simd_base<T, Abi>& r) noexcept { return simd_base<T, Abi>(Abi::mul(simd_base_memory, r.native_simd_type())); }

    public:
        simd_base<T, Abi> operator< (simd_base<T, Abi>& r) noexcept { return simd_base<T, Abi>(Abi::cmp_lt(simd_base_memory, r.native_simd_type())); }
        simd_base<T, Abi> operator> (simd_base<T, Abi>& r) noexcept { return simd_base<T, Abi>(Abi::cmp_gt(simd_base_memory, r.native_simd_type())); }
        simd_base<T, Abi> operator==(simd_base<T, Abi>& r) noexcept { return simd_base<T, Abi>(Abi::cmp_eq(simd_base_memory, r.native_simd_type())); }
    };
}