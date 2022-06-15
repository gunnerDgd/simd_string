#pragma once
#include <stdint.h>
#include <string/traits/details/simd/sse/string_traits_simd_sse_type.h>

void
__synapse_string_traits_simd_sse_copy_from
	(__synapse_string_traits_simd_sse*, uint8_t*);

void
__synapse_string_traits_simd_sse_copy_to
	(__synapse_string_traits_simd_sse*, uint8_t*);