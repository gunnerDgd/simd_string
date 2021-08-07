#include <simd/abi/sse/sse_abi_integral.hpp>
#include <simd/abi/sse/sse_abi_floating.hpp>

#include <type_traits>

namespace simd {
    template <typename T, typename Abi = typename std::conditional<std::is_integral<T>::value, 
                                                                  abi_sse_integral<T>,
                                                                  abi_sse_floating<T>>::type>
    class simd_base
    {
    protected:
        typename Abi::simd_memory_t simd_base_memory;

    public:
        simd_base()                               { }
        simd_base(typename Abi::simd_memory_t&& m) { simd_base_memory = m;                        }
        simd_base(typename Abi::simd_memory_t&  m) { simd_base_memory = m;                        }

        simd_base(T*                            m) { simd_base_memory = Abi::simd_load((void*)m); }

    public:
        void store(T* m) { Abi::simd_store(simd_base_memory, (void*)m); }
        void load (T* m) { simd_base_memory = Abi::simd_load(m)       ; }

    public:
        typename Abi::simd_memory_t& native_simd_type() { return simd_base_memory; }
        
        simd_base<T, Abi> operator+(simd_base<T, Abi>& r) noexcept { return simd_base<T, Abi>(Abi::simd_add(simd_base_memory, r.native_simd_type())); }
        simd_base<T, Abi> operator-(simd_base<T, Abi>& r) noexcept { return simd_base<T, Abi>(Abi::simd_sub(simd_base_memory, r.native_simd_type())); }
        simd_base<T, Abi> operator*(simd_base<T, Abi>& r) noexcept { return simd_base<T, Abi>(Abi::simd_mul(simd_base_memory, r.native_simd_type())); }
    };
}