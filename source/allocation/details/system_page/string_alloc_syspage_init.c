#include <string/allocation/details/system_page/string_alloc_syspage_init.h>

#include <Windows.h>

__synapse_string_alloc_syspage*
__synapse_string_alloc_syspage_initialize
	(size_t pUnitCount, size_t pInitCount)
{
	__synapse_string_alloc_syspage* ptr_syspage
		= malloc(sizeof(__synapse_string_alloc_syspage));

	ptr_syspage->syspage_alloc_count
		= pUnitCount * pInitCount;
	ptr_syspage->syspage_alloc_unit
		= pUnitCount;
	ptr_syspage->syspage_alloc_ptr
		= VirtualAlloc(NULL, ptr_syspage->syspage_alloc_count * 4096, MEM_COMMIT, PAGE_READWRITE);

	return
		ptr_syspage;
}

void
__synapse_string_alloc_syspage_cleanup
	(__synapse_string_alloc_syspage* pSyspage)
{
	VirtualFree
		(pSyspage->syspage_alloc_ptr, 0, MEM_FREE);
	free
		(pSyspage);
}