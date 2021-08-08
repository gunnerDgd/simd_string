#include <simd/header/simd.hpp>
#include <iostream>

int main()
{
    int   a[4] = {1, 2, 3, 4},
          b[4] = {5, 6, 7, 8},
          c[4];

    simd::simd_base<int> a_sse(a), b_sse(b), c_sse;

    c_sse = a_sse * b_sse;
    c_sse.copy_to(c);

    for(auto&& i : c)
        std::cout << i << " ";
}