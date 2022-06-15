#include <string/traits/details/simd/sse/string_traits_simd_sse_copy.h>

void
__synapse_string_traits_simd_sse_copy_from
	(__synapse_string_traits_simd_sse* pSimd, uint8_t* pCopy)
{
	SYNAPSE_SIMD_SSE_LOAD_FROM(pSimd, pCopy);
}

void
__synapse_string_traits_simd_sse_copy_to
	(__synapse_string_traits_simd_sse* pSimd, uint8_t* pCopy)
{
	SYNAPSE_SIMD_SSE_STORE_TO(pSimd, pCopy);
}