#pragma once
#include <string/allocation/details/bucket/string_alloc_bucket_type.h>
#include <string/allocation/details/arch/x64_asm_export.h>

void*
__synapse_string_alloc_bucket_expand
	(__synapse_string_alloc_bucket*);

void
__synapse_string_alloc_bucket_shrink
	(__synapse_string_alloc_bucket*);

size_t
__synapse_string_alloc_retrieve_bucket_count
	(__synapse_string_alloc_bucket*);

size_t
__synapse_string_alloc_retrieve_unit_bucket_count
	(__synapse_string_alloc_bucket*);