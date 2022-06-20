#pragma once
#include <stdint.h>

typedef struct __synapse_string_alloc_bucket
{
	size_t
		bucket_alloc_unit_count,
		bucket_alloc_count	   ;
	void*
		bucket_alloc_pointer;
} __synapse_string_alloc_bucket;