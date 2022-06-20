#pragma once
#include <stdint.h>

typedef struct __synapse_string_alloc_syspage
{
	size_t
		syspage_alloc_unit ,
		syspage_alloc_count;

	void*
		syspage_alloc_ptr;
} __synapse_string_alloc_syspage;