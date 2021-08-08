#include <simd/header/simd.hpp>

#include <iostream>
#include <chrono>

alignas(16) uint8_t a[4096], b[4096];
int main()
{
    simd::simd_base<uint8_t> xmm0, xmm1, xmm2, xmm3;
    auto start = std::chrono::high_resolution_clock::now();

    for(int i = 0 ; i < 256 ; i += 4)
    {
        xmm0.copy_from(&a[i      *16]);
        xmm1.copy_from(&a[(i + 1)*16]);
        xmm2.copy_from(&a[(i + 2)*16]);
        xmm3.copy_from(&a[(i + 3)*16]); // 64 Byte.
        
        xmm0.copy_to(&b[i * 16]);
        xmm1.copy_to(&b[(i + 1)*16]);
        xmm2.copy_to(&b[(i + 2)*16]);
        xmm3.copy_to(&b[(i + 3)*16]);
    }
    auto end   = std::chrono::high_resolution_clock::now();
    std::cout << (end - start).count() << std::endl;

    start = std::chrono::high_resolution_clock::now();
    for(int i = 0 ; i < 4096 ; i++)
        b[i] = a[i];
    end   = std::chrono::high_resolution_clock::now();

    std::cout << (end - start).count() << std::endl;
}