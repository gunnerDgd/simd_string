#include <string/allocation/details/bucket/string_alloc_bucket_allocation.h>

#include <stdalign.h>
#include <stdlib.h>

void*
__synapse_string_alloc_bucket_expand
	(__synapse_string_alloc_bucket* pBucket)
{
	void* ptr_realloc
		= _aligned_malloc(pBucket->bucket_alloc_count * 256, 128);
	
	__synapse_string_alloc_sse_copy
		(ptr_realloc, pBucket->bucket_alloc_pointer, pBucket->bucket_alloc_count);
	
	pBucket->bucket_alloc_count <<= 1;
	
	_aligned_free
		(pBucket->bucket_alloc_pointer);
	pBucket->bucket_alloc_pointer
		= ptr_realloc;

	return
		ptr_realloc;
}

void
__synapse_string_alloc_bucket_shrink
	(__synapse_string_alloc_bucket* pBucket)
{
	void* ptr_realloc
		= _aligned_malloc(pBucket->bucket_alloc_count * 64, 128);

	__synapse_string_alloc_sse_copy
		(ptr_realloc, pBucket->bucket_alloc_pointer, (pBucket->bucket_alloc_count >> 1));
	
	pBucket->bucket_alloc_count >>= 1;

	_aligned_free
		(pBucket->bucket_alloc_pointer);
	pBucket->bucket_alloc_pointer
		= ptr_realloc;

	return
		ptr_realloc;
}

size_t
__synapse_string_alloc_retrieve_bucket_count
	(__synapse_string_alloc_bucket* pBucket)
{
	return
		pBucket->bucket_alloc_count;
}

size_t
__synapse_string_alloc_retrieve_unit_bucket_count
	(__synapse_string_alloc_bucket* pBucket)
{
	return
		pBucket->bucket_alloc_unit_count;
}