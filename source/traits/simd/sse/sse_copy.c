#include <string/traits/simd/sse/sse_copy.h>
#include <string/traits/details/simd/sse/string_traits_simd_sse_copy.h>

void
synapse_string_traits_simd_sse_copy_from
	(synapse_string_traits_simd_sse pSimd, uint8_t* pMemory)
{
	__synapse_string_traits_simd_sse_copy_from
		(pSimd.opaque, pMemory);
}

void
synapse_string_traits_simd_sse_copy_to
	(synapse_string_traits_simd_sse pSimd, uint8_t* pMemory)
{
	__synapse_string_traits_simd_sse_copy_to
		(pSimd.opaque, pMemory);
}