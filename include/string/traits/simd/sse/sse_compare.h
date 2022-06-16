#pragma once
#include <string/traits/simd/sse/sse_type.h>
#include <stdint.h>

int
synapse_string_traits_simd_sse_compare_eq
	(uint8_t*, uint8_t*, size_t);

int
synapse_string_traits_simd_sse_compare_eq_register
	(synapse_string_traits_simd_sse, synapse_string_traits_simd_sse);

int
synapse_string_traits_simd_sse_compare_gt
	(uint8_t*, uint8_t*, size_t);

int
synapse_string_traits_simd_sse_compare_gt_register
	(synapse_string_traits_simd_sse, synapse_string_traits_simd_sse);

int
synapse_string_traits_simd_sse_compare_lt
	(uint8_t*, uint8_t*, size_t);

int
synapse_string_traits_simd_sse_compare_lt_register
	(synapse_string_traits_simd_sse, synapse_string_traits_simd_sse);

int
synapse_string_traits_simd_sse_compare_eq128
	(uint8_t*, uint8_t*, size_t);

int
synapse_string_traits_simd_sse_compare_eq64
	(uint8_t*, uint8_t*, size_t);

int
synapse_string_traits_simd_sse_compare_gt128
	(uint8_t*, uint8_t*, size_t);

int
synapse_string_traits_simd_sse_compare_gt64
	(uint8_t*, uint8_t*, size_t);

int
synapse_string_traits_simd_sse_compare_lt128
	(uint8_t*, uint8_t*, size_t);

int
synapse_string_traits_simd_sse_compare_lt64
	(uint8_t*, uint8_t*, size_t);