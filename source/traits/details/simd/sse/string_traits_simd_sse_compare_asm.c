#include <string/traits/details/simd/sse/string_traits_simd_sse_compare_asm.h>

int
__synapse_string_simd_sse_compare_eq128_n
	(uint8_t* pLhs, uint8_t* pRhs, size_t pCount)
{
	int res_cmp = 0;
	while (--pCount != (size_t)-1 && !res_cmp)
	{
		__synapse_string_simd_sse_compare_eq128
			(pLhs + pCount * 128, pRhs + pCount * 64);
	}

	return res_cmp;
}

int
__synapse_string_simd_sse_compare_eq64_n
	(uint8_t* pLhs, uint8_t* pRhs, size_t pCount)
{
	int res_cmp = 0;
	while (--pCount != (size_t)-1 && !res_cmp)
	{
		__synapse_string_simd_sse_compare_eq64
			(pLhs + pCount * 64, pRhs + pCount * 64);
	}

	return res_cmp;
}

int
__synapse_string_simd_sse_compare_gt128_n
	(uint8_t* pLhs, uint8_t* pRhs, size_t pCount)
{
	int res_cmp = 0;
	while (--pCount != (size_t)-1 && !res_cmp)
	{
		__synapse_string_simd_sse_compare_gt128
			(pLhs + pCount * 128, pRhs + pCount * 128);
	}

	return res_cmp;
}

int
__synapse_string_simd_sse_compare_gt64_n
	(uint8_t* pLhs, uint8_t* pRhs, size_t pCount)
{
	int res_cmp = 0;
	while (--pCount != (size_t)-1 && !res_cmp)
	{
		__synapse_string_simd_sse_compare_gt64
			(pLhs + pCount * 64, pRhs + pCount * 64);
	}

	return res_cmp;
}

int
__synapse_string_simd_sse_compare_lt128_n
	(uint8_t* pLhs, uint8_t* pRhs, size_t pCount)
{
	int res_cmp = 0;
	while (--pCount != (size_t)-1 && !res_cmp)
	{
		__synapse_string_simd_sse_compare_lt128
			(pLhs + pCount * 128, pRhs + pCount * 128);
	}

	return res_cmp;
}

int
__synapse_string_simd_sse_compare_lt64_n
	(uint8_t* pLhs, uint8_t* pRhs, size_t pCount)
{
	int res_cmp = 0;
	while (--pCount != (size_t)-1 && !res_cmp)
	{
		__synapse_string_simd_sse_compare_lt64
			(pLhs + pCount * 64, pRhs + pCount * 64);
	}

	return res_cmp;
}