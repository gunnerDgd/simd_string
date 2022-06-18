#pragma once
#include <string/allocation/details/bucket/string_alloc_bucket_type.h>

size_t
__synapse_string_alloc_bucket_copy_from
	(__synapse_string_alloc_bucket*, void*, size_t);

size_t
__synapse_string_alloc_bucket_copy_to
	(__synapse_string_alloc_bucket*, void*, size_t);