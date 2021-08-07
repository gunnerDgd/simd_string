#include <simd/header/simd.hpp>
#include <iostream>

int main()
{
    float a[4] = {1.1, 2.2, 3.3, 4.4},
          b[4] = {5.5, 6.6, 7.7, 8.8},
          c[4];

    simd::simd_base<float> a_sse(a), b_sse(b), c_sse;

    c_sse = a_sse + b_sse;
    c_sse.store(c);

    for(auto&& i : c)
        std::cout << i << " ";
}