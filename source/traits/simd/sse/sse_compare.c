#include <string/traits/simd/sse/sse_compare.h>
#include <string/traits/details/simd/sse/string_traits_simd_sse_compare.h>
#include <string/traits/details/simd/sse/string_traits_simd_sse_compare_asm.h>

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

int
synapse_string_traits_simd_sse_compare_eq128
	(uint8_t* pLhs, uint8_t* pRhs, size_t pCount)
{
	_mm_prefetch(pLhs, _MM_HINT_T2);
	_mm_prefetch(pRhs, _MM_HINT_T2);

	return
		__synapse_string_simd_sse_compare_eq128_n(pLhs, pRhs, pCount);
}

int
synapse_string_traits_simd_sse_compare_eq64
	(uint8_t* pLhs, uint8_t* pRhs, size_t pCount)
{
	_mm_prefetch(pLhs, _MM_HINT_T2);
	_mm_prefetch(pRhs, _MM_HINT_T2);

	return
		__synapse_string_simd_sse_compare_eq64_n(pLhs, pRhs, pCount);
}

int
synapse_string_traits_simd_sse_compare_gt128
	(uint8_t* pLhs, uint8_t* pRhs, size_t pCount)
{
	_mm_prefetch(pLhs, _MM_HINT_T2);
	_mm_prefetch(pRhs, _MM_HINT_T2);

	return
		__synapse_string_simd_sse_compare_gt128_n(pLhs, pRhs, pCount);
}

int
synapse_string_traits_simd_sse_compare_gt64
	(uint8_t* pLhs, uint8_t* pRhs, size_t pCount)
{
	_mm_prefetch(pLhs, _MM_HINT_T2);
	_mm_prefetch(pRhs, _MM_HINT_T2);

	return
		__synapse_string_simd_sse_compare_gt64_n(pLhs, pRhs, pCount);
}

int
synapse_string_traits_simd_sse_compare_lt128
	(uint8_t* pLhs, uint8_t* pRhs, size_t pCount)
{
	_mm_prefetch(pLhs, _MM_HINT_T2);
	_mm_prefetch(pRhs, _MM_HINT_T2);

	return
		__synapse_string_simd_sse_compare_lt128_n(pLhs, pRhs, pCount);
}

int
synapse_string_traits_simd_sse_compare_lt64
	(uint8_t* pLhs, uint8_t* pRhs, size_t pCount)
{
	_mm_prefetch(pLhs, _MM_HINT_T2);
	_mm_prefetch(pRhs, _MM_HINT_T2);

	return
		__synapse_string_simd_sse_compare_lt64_n(pLhs, pRhs, pCount);
}