#include <string/traits/details/simd/sse/string_traits_simd_sse_init.h>
#include <stdalign.h>

__synapse_string_traits_simd_sse*
__synapse_string_traits_simd_sse_allocate()
{
	return
		_aligned_malloc(64, 64);
}

void
__synapse_string_traits_simd_sse_deallocate
	(__synapse_string_traits_simd_sse* pDealloc)
{
	_aligned_free(pDealloc);
}