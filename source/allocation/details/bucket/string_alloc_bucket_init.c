#include <string/allocation/details/bucket/string_alloc_bucket_init.h>

#include <stdalign.h>
#include <stdlib.h>

__synapse_string_alloc_bucket*
__synapse_string_alloc_bucket_initialize
	(size_t pUnitCount, size_t pInitCount)
{
	__synapse_string_alloc_bucket* ptr_alloc
		= malloc(sizeof(__synapse_string_alloc_bucket));

	ptr_alloc->bucket_alloc_count
		= pUnitCount * pInitCount;
	ptr_alloc->bucket_alloc_unit_count
		= pUnitCount;
	ptr_alloc->bucket_alloc_pointer
		= _aligned_malloc(ptr_alloc->bucket_alloc_count * 128, 128);

	return
		ptr_alloc;
}

void
__synapse_string_alloc_bucket_cleanup
	(__synapse_string_alloc_bucket* pBucket)
{
	_aligned_free(pBucket->bucket_alloc_pointer);
	free		 (pBucket);
}