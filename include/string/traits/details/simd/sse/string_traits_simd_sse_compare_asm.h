#pragma once
#include <string/traits/details/simd/sse/string_traits_simd_sse_type.h>
#include <stdint.h>

// ASM Exported Functions

int
__synapse_string_simd_sse_compare_eq128
	(uint8_t*, uint8_t*);

int
__synapse_string_simd_sse_compare_lt128
	(uint8_t*, uint8_t*);

int
__synapse_string_simd_sse_compare_gt128
	(uint8_t*, uint8_t*);

int
__synapse_string_simd_sse_compare_eq64
	(uint8_t*, uint8_t*);

int
__synapse_string_simd_sse_compare_lt64
	(uint8_t*, uint8_t*);

int
__synapse_string_simd_sse_compare_gt64
	(uint8_t*, uint8_t*);


int
__synapse_string_simd_sse_compare_eq128_n
	(uint8_t*, uint8_t*, size_t);

int
__synapse_string_simd_sse_compare_eq64_n
	(uint8_t*, uint8_t*, size_t);

int
__synapse_string_simd_sse_compare_gt128_n
	(uint8_t*, uint8_t*, size_t);

int
__synapse_string_simd_sse_compare_gt64_n
	(uint8_t*, uint8_t*, size_t);

int
__synapse_string_simd_sse_compare_lt128_n
	(uint8_t*, uint8_t*, size_t);

int
__synapse_string_simd_sse_compare_lt64_n
	(uint8_t*, uint8_t*, size_t);