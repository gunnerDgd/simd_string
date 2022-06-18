#include <string/allocation/details/bucket/string_alloc_bucket_init.h>

#include <stdalign.h>
#include <string.h>
#include <stdlib.h>

__synapse_string_alloc_bucket*
__synapse_string_alloc_bucket_initialize
	(size_t pAllocSize, size_t pInitAllocCount)
{
	__synapse_string_alloc_bucket* ptr_bucket
		= malloc(sizeof(__synapse_string_alloc_bucket));

	memset(ptr_bucket, 0x00, sizeof(__synapse_string_alloc_bucket));

	ptr_bucket->bucket_align_size =
			(pAllocSize % 64) ? pAllocSize : (pAllocSize / 64) + 1;
	ptr_bucket->bucket_alloc_size =
		ptr_bucket->bucket_align_size * pInitAllocCount;
	ptr_bucket->bucket_alloc =
		synapse_structure_double_linked_initialize_default();

	while (--pInitAllocCount != (size_t)-1)
	{
		__synapse_string_alloc_bucket_node* ptr_node
			= malloc(sizeof(__synapse_string_alloc_bucket_node));

		ptr_node->bucket_ptr
			= _aligned_malloc(ptr_node, ptr_bucket->bucket_align_size);
		ptr_node->bucket_count
			= 1;

		synapse_structure_double_linked_insert_back
			(ptr_bucket->bucket_alloc, &ptr_node, sizeof(void*));
	}
}

void
__synapse_string_alloc_bucket_cleanup(__synapse_string_alloc_bucket* pDealloc)
{
	synapse_structure_double_linked_cleanup
		(pDealloc->bucket_alloc);
	free(pDealloc);
}