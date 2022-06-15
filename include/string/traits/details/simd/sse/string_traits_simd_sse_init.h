#pragma once
#include <string/traits/details/simd/sse/string_traits_simd_sse_type.h>

__synapse_string_traits_simd_sse*
__synapse_string_traits_simd_sse_allocate  ();

void
__synapse_string_traits_simd_sse_deallocate
	(__synapse_string_traits_simd_sse*);