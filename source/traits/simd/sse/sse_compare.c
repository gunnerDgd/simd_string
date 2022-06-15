#include <string/traits/simd/sse/sse_compare.h>
#include <string/traits/details/simd/sse/string_traits_simd_sse_compare.h>

int
synapse_string_traits_simd_sse_compare_eq
	(uint8_t* pLhs, uint8_t* pRhs, size_t pCount)
{
	return
		__synapse_string_traits_simd_sse_compare_equal(pLhs, pRhs, pCount);
}

int
synapse_string_traits_simd_sse_compare_eq_register
	(synapse_string_traits_simd_sse pLhs, synapse_string_traits_simd_sse pRhs)
{
	_mm_prefetch(pLhs.opaque, _MM_HINT_T2);
	_mm_prefetch(pRhs.opaque, _MM_HINT_T2);

	return
		__synapse_string_traits_simd_sse_compare_equal_register
			(pLhs.opaque, pRhs.opaque);
}

int
synapse_string_traits_simd_sse_compare_gt
	(uint8_t* pLhs, uint8_t* pRhs, size_t pCount)
{
	return
		__synapse_string_traits_simd_sse_compare_greater_than
			(pLhs, pRhs, pCount);
}

int
synapse_string_traits_simd_sse_compare_gt_register
	(synapse_string_traits_simd_sse pLhs, synapse_string_traits_simd_sse pRhs)
{
	_mm_prefetch(pLhs.opaque, _MM_HINT_T2);
	_mm_prefetch(pRhs.opaque, _MM_HINT_T2);

	return
		__synapse_string_traits_simd_sse_compare_greater_than_register
			(pLhs.opaque, pRhs.opaque);
}

int
synapse_string_traits_simd_sse_compare_lt
	(uint8_t* pLhs, uint8_t* pRhs, size_t pCount)
{
	return
		__synapse_string_traits_simd_sse_compare_less_than
			(pLhs, pRhs, pCount);
}

int
synapse_string_traits_simd_sse_compare_lt_register
	(synapse_string_traits_simd_sse pLhs, synapse_string_traits_simd_sse pRhs)
{
	_mm_prefetch(pLhs.opaque, _MM_HINT_T2);
	_mm_prefetch(pRhs.opaque, _MM_HINT_T2);

	return
		__synapse_string_traits_simd_sse_compare_less_than_register
			(pLhs.opaque, pRhs.opaque);
}