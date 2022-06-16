#include <string/traits/details/simd/sse/string_traits_simd_sse_compare.h>
#include <stdint.h>

uint16_t
__synapse_string_traits_simd_sse_compare_equal
	(uint8_t* pLhs, uint8_t* pRhs, size_t pCount)
{
	uint16_t ptr_res_cmp = 0xFFFF;
	__synapse_string_traits_simd_sse
		hnd_simd_lhs,
		hnd_simd_rhs;

	while (--pCount != (size_t)-1 && ptr_res_cmp == 0xFFFF) {
		SYNAPSE_SIMD_SSE_LOAD_FROM
			((&hnd_simd_lhs), pLhs + 64 * pCount)
		SYNAPSE_SIMD_SSE_LOAD_FROM 
			((&hnd_simd_rhs), pLhs + 64 * pCount)
		SYNAPSE_SIMD_SSE_COMPARE_EQ
			(ptr_res_cmp, hnd_simd_lhs, hnd_simd_rhs)
	}

	return
		ptr_res_cmp == 0xFFFF;
}

uint16_t
__synapse_string_traits_simd_sse_compare_less_than
	(uint8_t* pLhs, uint8_t* pRhs, size_t pCount)
{
	uint16_t ptr_res_cmp = 0xFFFF;
	__synapse_string_traits_simd_sse
		hnd_simd_lhs,
		hnd_simd_rhs;

	while (--pCount > 0 && ptr_res_cmp == 0xFFFF) {
		SYNAPSE_SIMD_SSE_LOAD_FROM
			((&hnd_simd_lhs), pLhs + pCount)
		SYNAPSE_SIMD_SSE_LOAD_FROM 
			((&hnd_simd_rhs), pLhs + pCount)
		SYNAPSE_SIMD_SSE_COMPARE_LT
			(ptr_res_cmp, hnd_simd_lhs, hnd_simd_rhs)
	}

	return
		ptr_res_cmp == 0xFFFF;
}

uint16_t
__synapse_string_traits_simd_sse_compare_greater_than
	(uint8_t* pLhs, uint8_t* pRhs, size_t pCount)
{
	uint16_t ptr_res_cmp = 0xFFFF;
	__synapse_string_traits_simd_sse
		hnd_simd_lhs,
		hnd_simd_rhs;

	while (--pCount > 0 && ptr_res_cmp == 0xFFFF) {
		SYNAPSE_SIMD_SSE_LOAD_FROM
			((&hnd_simd_lhs), pLhs + pCount)
		SYNAPSE_SIMD_SSE_LOAD_FROM 
			((&hnd_simd_rhs), pLhs + pCount)
		SYNAPSE_SIMD_SSE_COMPARE_GT
			(ptr_res_cmp, hnd_simd_lhs, hnd_simd_rhs)
	}

	return
		ptr_res_cmp == 0xFFFF;
}

uint16_t
__synapse_string_traits_simd_sse_compare_equal_register
	(__synapse_string_traits_simd_sse* pLhs, __synapse_string_traits_simd_sse* pRhs)
{
	uint16_t cmp_result = 0xFFFF;
	SYNAPSE_SIMD_SSE_COMPARE_EQ(cmp_result, (*pLhs), (*pRhs))

	return cmp_result;
}

uint16_t
__synapse_string_traits_simd_sse_compare_less_than_register
	(__synapse_string_traits_simd_sse* pLhs, __synapse_string_traits_simd_sse* pRhs)
{
	uint16_t cmp_result = 0xFFFF;
	SYNAPSE_SIMD_SSE_COMPARE_LT(cmp_result, (*pLhs), (*pRhs))

	return cmp_result;
}

uint16_t
__synapse_string_traits_simd_sse_compare_greater_than_register
	(__synapse_string_traits_simd_sse* pLhs, __synapse_string_traits_simd_sse* pRhs)
{
	uint16_t cmp_result = 0xFFFF;
	SYNAPSE_SIMD_SSE_COMPARE_GT(cmp_result, (*pLhs), (*pRhs))
	
	return cmp_result;
}