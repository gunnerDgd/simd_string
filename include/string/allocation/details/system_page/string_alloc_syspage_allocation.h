#pragma once
#include <string/allocation/details/system_page/string_alloc_syspage_type.h>

#define __synapse_string_alloc_syspage_expand_size(pPrevCount)\
	(((pPrevCount << 12) << 1) + 1)

#define __synapse_string_alloc_syspage_shrink_size(pPrevCount)\
	(((pPrevCount << 12) >> 1) + 1)

#define __synapse_string_alloc_syspage_register_count(pPageCount)\
	((pPageCount << 12) >> 7)

void*
__synapse_string_alloc_syspage_expand
	(__synapse_string_alloc_syspage*);

void*
__synapse_string_alloc_syspage_shrink
	(__synapse_string_alloc_syspage*);

size_t
__synapse_string_alloc_syspage_retrieve_unit_size
	(__synapse_string_alloc_syspage*);

size_t
__synapse_string_alloc_syspage_retrieve_count
	(__synapse_string_alloc_syspage*);