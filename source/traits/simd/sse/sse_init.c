#include <string/traits/simd/sse/sse_init.h>
#include <string/traits/details/simd/sse/string_traits_simd_sse_init.h>

synapse_string_traits_simd_sse
synapse_string_traits_simd_sse_allocate()
{
	synapse_string_traits_simd_sse ptr_simd
		= { .opaque = __synapse_string_traits_simd_sse_allocate() };

	return ptr_simd;
}

void
synapse_string_traits_simd_sse_deallocate
	(synapse_string_traits_simd_sse pSimd)
{
	__synapse_string_traits_simd_sse_deallocate
		(pSimd.opaque);
}