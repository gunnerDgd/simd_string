#pragma once
#include <string/allocation/details/string_alloc_type.h>

__synapse_string_alloc_entity*
__synapse_string_alloc_initialize();

void
__synapse_string_alloc_cleanup	 (__synapse_string_alloc_entity*);

void
__synapse_string_alloc_allocate  (__synapse_string_alloc_entity*, size_t);

void
__synapse_string_alloc_deallocate(__synapse_string_alloc_entity*);