#include <string/allocation/details/system_page/string_alloc_syspage_allocation.h>
#include <string/allocation/details/arch/x64_asm_export.h>

#include <Windows.h>

void*
__synapse_string_alloc_syspage_expand
	(__synapse_string_alloc_syspage* pSyspage)
{
	void* ptr_realloc
		= VirtualAlloc
			(NULL,
			 __synapse_string_alloc_syspage_expand_size(pSyspage->syspage_alloc_count), 
			 MEM_COMMIT, PAGE_READWRITE);

	__synapse_string_alloc_sse_copy
		(ptr_realloc, pSyspage->syspage_alloc_ptr,
			__synapse_string_alloc_syspage_register_count(pSyspage->syspage_alloc_count));
	
	VirtualFree
		(pSyspage->syspage_alloc_ptr, 0, MEM_FREE);

	pSyspage->syspage_alloc_count <<= 1;
	pSyspage->syspage_alloc_ptr     = ptr_realloc;

	return
		ptr_realloc;
}

void*
__synapse_string_alloc_syspage_shrink
	(__synapse_string_alloc_syspage* pSyspage)
{
	void* ptr_realloc
		= VirtualAlloc
			(NULL, 
			 __synapse_string_alloc_syspage_shrink_size(pSyspage->syspage_alloc_count), 
			 MEM_COMMIT, PAGE_READWRITE);

	pSyspage->syspage_alloc_count
		= __synapse_string_alloc_syspage_shrink_size(pSyspage->syspage_alloc_count);
	__synapse_string_alloc_sse_copy
		(ptr_realloc, pSyspage->syspage_alloc_ptr,
			__synapse_string_alloc_syspage_register_count(pSyspage->syspage_alloc_count));
	
	VirtualFree
		(pSyspage->syspage_alloc_ptr, 0, MEM_FREE);

	pSyspage->syspage_alloc_ptr = ptr_realloc;
	return
		ptr_realloc;
}

size_t
__synapse_string_alloc_syspage_retrieve_unit_size
	(__synapse_string_alloc_syspage* pSyspage)
{
	return
		pSyspage->syspage_alloc_unit;
}

size_t
__synapse_string_alloc_syspage_retrieve_count
	(__synapse_string_alloc_syspage* pSyspage)
{
	return
		pSyspage->syspage_alloc_count;
}