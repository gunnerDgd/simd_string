#include <string/allocation/details/bucket/string_alloc_bucket_manip.h>

#include <stdalign.h>
#include <stdlib.h>
#include <string.h>

__synapse_string_alloc_bucket_node*
__synapse_string_alloc_bucket_node_retrieve
	(__synapse_string_alloc_bucket* pBucket, size_t pIndex)
{
	return
		*(__synapse_string_alloc_bucket_node**)
			synapse_structure_double_linked_node_data(
				synapse_structure_double_linked_retrieve_at(pBucket->bucket_alloc, pIndex)
		);
}

__synapse_string_alloc_bucket_node*
__synapse_string_alloc_bucket_node_retrieve_front
	(__synapse_string_alloc_bucket* pBucket)
{
	return
		*(__synapse_string_alloc_bucket_node**)
			synapse_structure_double_linked_node_data(
				synapse_structure_double_linked_node_begin(pBucket->bucket_alloc)
		);
}

__synapse_string_alloc_bucket_node*
__synapse_string_alloc_bucket_node_retrieve_back
	(__synapse_string_alloc_bucket* pBucket)
{
	return
		*(__synapse_string_alloc_bucket_node**)
			synapse_structure_double_linked_node_data(
				synapse_structure_double_linked_node_end(pBucket->bucket_alloc)
		);
}

void
__synapse_string_alloc_bucket_node_push
	(__synapse_string_alloc_bucket* pBucket, size_t pPushCount, size_t pPushIndex)
{
	__synapse_string_alloc_bucket_node* ptr_node
		= malloc(sizeof(__synapse_string_alloc_bucket_node));

	ptr_node->bucket_count
		= pPushCount;
	ptr_node->bucket_ptr
		= _aligned_malloc(pPushCount * pBucket->bucket_align_size,
									   pBucket->bucket_align_size);

	synapse_structure_double_linked_insert_at
		(pBucket->bucket_alloc, &ptr_node, sizeof(void*), pPushIndex);
}

void
__synapse_string_alloc_bucket_node_push_back
	(__synapse_string_alloc_bucket* pBucket, size_t pPushCount)
{
	__synapse_string_alloc_bucket_node* ptr_node
		= malloc(sizeof(__synapse_string_alloc_bucket_node));

	ptr_node->bucket_count
		= pPushCount;
	ptr_node->bucket_ptr
		= _aligned_malloc(pPushCount * pBucket->bucket_align_size,
									   pBucket->bucket_align_size);

	synapse_structure_double_linked_insert_back
		(pBucket->bucket_alloc, &ptr_node, sizeof(void*));
}

void
__synapse_string_alloc_bucket_node_push_front
	(__synapse_string_alloc_bucket* pBucket, size_t pPushCount)
{
	__synapse_string_alloc_bucket_node* ptr_node
		= malloc(sizeof(__synapse_string_alloc_bucket_node));

	ptr_node->bucket_count
		= pPushCount;
	ptr_node->bucket_ptr
		= _aligned_malloc(pPushCount * pBucket->bucket_align_size,
									   pBucket->bucket_align_size);

	synapse_structure_double_linked_insert_front
		(pBucket->bucket_alloc, &ptr_node, sizeof(void*));
}

void
__synapse_string_alloc_bucket_node_pop
	(__synapse_string_alloc_bucket* pBucket, size_t pPopIndex)
{
	__synapse_string_alloc_bucket_node* ptr_node =
		*(__synapse_string_alloc_bucket_node**)
			synapse_structure_double_linked_node_data(
				synapse_structure_double_linked_retrieve_at(pBucket->bucket_alloc, pPopIndex)
		);

	if (!ptr_node)
		return;

	_aligned_free(ptr_node->bucket_ptr);
	free		 (ptr_node);

	synapse_structure_double_linked_erase_at
		(pBucket->bucket_alloc, pPopIndex);
}

void
__synapse_string_alloc_bucket_node_pop_back
	(__synapse_string_alloc_bucket* pBucket)
{
	__synapse_string_alloc_bucket_node* ptr_node =
		*(__synapse_string_alloc_bucket_node**)
			synapse_structure_double_linked_node_data(
				synapse_structure_double_linked_node_end(pBucket->bucket_alloc)
		);

	if (!ptr_node)
		return;

	_aligned_free(ptr_node->bucket_ptr);
	free		 (ptr_node);

	synapse_structure_double_linked_erase_back
		(pBucket->bucket_alloc);
}

void
__synapse_string_alloc_bucket_node_pop_front
	(__synapse_string_alloc_bucket* pBucket)
{
	__synapse_string_alloc_bucket_node* ptr_node =
		*(__synapse_string_alloc_bucket_node**)
			synapse_structure_double_linked_node_data(
				synapse_structure_double_linked_node_begin(pBucket->bucket_alloc)
		);

	if (!ptr_node)
		return;

	_aligned_free(ptr_node->bucket_ptr);
	free		 (ptr_node);

	synapse_structure_double_linked_erase_front
		(pBucket->bucket_alloc);
}