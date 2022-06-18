#pragma once
#include <string/allocation/details/bucket/string_alloc_bucket_type.h>

__synapse_string_alloc_bucket*
__synapse_string_alloc_bucket_initialize(size_t, size_t);

void
__synapse_string_alloc_bucket_cleanup   (__synapse_string_alloc_bucket*);