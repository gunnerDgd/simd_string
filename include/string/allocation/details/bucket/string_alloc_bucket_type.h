#pragma once
#include <stdint.h>
#include <structure/list/double_linked.h>

typedef struct __synapse_string_alloc_bucket_node
{
	void*
		bucket_ptr;
	size_t
		bucket_count;
} __synapse_string_alloc_bucket_node;

typedef struct __synapse_string_alloc_bucket
{
	synapse_structure_double_linked
		bucket_alloc;

	size_t
		bucket_align_size	,
		bucket_alloc_size   ,
		bucket_occupied_size;
} __synapse_string_alloc_bucket;