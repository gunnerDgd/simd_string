#pragma once
#include <stdint.h>
#include <string/traits/simd/sse/sse_type.h>

synapse_string_traits_simd_sse
synapse_string_traits_simd_sse_copy_from(uint8_t*);

void
synapse_string_traits_simd_sse_copy_to
	(synapse_string_traits_simd_sse, uint8_t*);