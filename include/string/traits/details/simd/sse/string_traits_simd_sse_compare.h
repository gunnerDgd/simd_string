#pragma once
#include <string/traits/details/simd/sse/string_traits_simd_sse_type.h>

uint16_t
__synapse_string_traits_simd_sse_compare_equal
	(uint8_t*, uint8_t*, size_t);

uint16_t
__synapse_string_traits_simd_sse_compare_equal_register
	(__synapse_string_traits_simd_sse*, __synapse_string_traits_simd_sse*);

uint16_t
__synapse_string_traits_simd_sse_compare_less_than
	(uint8_t*, uint8_t*, size_t);

uint16_t
__synapse_string_traits_simd_sse_compare_less_than_register
	(__synapse_string_traits_simd_sse*, __synapse_string_traits_simd_sse*);

uint16_t
__synapse_string_traits_simd_sse_compare_greater_than
	(uint8_t*, uint8_t*, size_t);

uint16_t
__synapse_string_traits_simd_sse_compare_greater_than_register
	(__synapse_string_traits_simd_sse*, __synapse_string_traits_simd_sse*);