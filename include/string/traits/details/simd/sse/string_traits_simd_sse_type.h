#pragma once
#include <pmmintrin.h>

typedef struct __synapse_string_traits_simd_sse
{
	__m128i hnd_sse_block[4]; // 16 * 4 = 64 Byte.
} __synapse_string_traits_simd_sse;


#define SYNAPSE_SIMD_SSE_LOAD_FROM(pSimd, pMemory)			 \
	pSimd->hnd_sse_block[0] = _mm_load_si128(pMemory);		 \
	pSimd->hnd_sse_block[1] = _mm_load_si128(pMemory + 16);	 \
	pSimd->hnd_sse_block[2] = _mm_load_si128(pMemory + 16 * 2);\
	pSimd->hnd_sse_block[3] = _mm_load_si128(pMemory + 16 * 3);

#define SYNAPSE_SIMD_SSE_STORE_TO(pSimd, pMemory)			   \
	_mm_store_si128(pMemory		    , pSimd->hnd_sse_block[0]);\
	_mm_store_si128(pMemory + 16	, pSimd->hnd_sse_block[1]);\
	_mm_store_si128(pMemory + 16 * 2, pSimd->hnd_sse_block[2]);\
	_mm_store_si128(pMemory + 16 * 3, pSimd->hnd_sse_block[3]);

#define SYNAPSE_SIMD_SSE_COMPARE_EQ(pResult, pLhs, pRhs)\
	pResult &= _mm_movemask_epi8(\
		_mm_cmpeq_epi32(pLhs.hnd_sse_block[0], pRhs.hnd_sse_block[0]));\
	pResult &= _mm_movemask_epi8(\
		_mm_cmpeq_epi32(pLhs.hnd_sse_block[1], pRhs.hnd_sse_block[1]));\
	pResult &= _mm_movemask_epi8(\
		_mm_cmpeq_epi32(pLhs.hnd_sse_block[2], pRhs.hnd_sse_block[2]));\
	pResult &= _mm_movemask_epi8(\
		_mm_cmpeq_epi32(pLhs.hnd_sse_block[3], pRhs.hnd_sse_block[3]));

#define SYNAPSE_SIMD_SSE_COMPARE_LT(pResult, pLhs, pRhs)\
	pResult &= _mm_movemask_epi8(\
		_mm_cmplt_epi32(pLhs.hnd_sse_block[0], pRhs.hnd_sse_block[0]));\
	pResult &= _mm_movemask_epi8(\
		_mm_cmplt_epi32(pLhs.hnd_sse_block[1], pRhs.hnd_sse_block[1]));\
	pResult &= _mm_movemask_epi8(\
		_mm_cmplt_epi32(pLhs.hnd_sse_block[2], pRhs.hnd_sse_block[2]));\
	pResult &= _mm_movemask_epi8(\
		_mm_cmplt_epi32(pLhs.hnd_sse_block[3], pRhs.hnd_sse_block[3]));

#define SYNAPSE_SIMD_SSE_COMPARE_GT(pResult, pLhs, pRhs)\
	pResult &= _mm_movemask_epi8(\
		_mm_cmpgt_epi32(pLhs.hnd_sse_block[0], pRhs.hnd_sse_block[0]));\
	pResult &= _mm_movemask_epi8(\
		_mm_cmpgt_epi32(pLhs.hnd_sse_block[1], pRhs.hnd_sse_block[1]));\
	pResult &= _mm_movemask_epi8(\
		_mm_cmpgt_epi32(pLhs.hnd_sse_block[2], pRhs.hnd_sse_block[2]));\
	pResult &= _mm_movemask_epi8(\
		_mm_cmpgt_epi32(pLhs.hnd_sse_block[3], pRhs.hnd_sse_block[3]));