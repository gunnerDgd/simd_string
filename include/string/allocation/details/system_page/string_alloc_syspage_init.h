#pragma once
#include <string/allocation/details/system_page/string_alloc_syspage_type.h>

__synapse_string_alloc_syspage*
__synapse_string_alloc_syspage_initialize
	(size_t, size_t);

void
__synapse_string_alloc_syspage_cleanup
	(__synapse_string_alloc_syspage*);