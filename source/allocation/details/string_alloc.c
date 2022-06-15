#include <string/allocation/details/string_alloc.h>
#include <Windows.h>

__synapse_string_alloc_entity*
__synapse_string_alloc_initialize()
{
	__synapse_string_alloc_entity* ptr_entity =
		malloc(sizeof(__synapse_string_alloc_entity));

	ptr_entity->entry			 
		= malloc(sizeof(__synapse_string_alloc_block_node));
	ptr_entity->entry->ptr_block 
		= VirtualAlloc(ptr_entity, 4096, MEM_COMMIT, PAGE_READWRITE);
	
	ptr_entity->backmost   = ptr_entity->entry;
	ptr_entity->frontmost  = ptr_entity->entry;

	ptr_entity->used_count  = 0;
	ptr_entity->alloc_count = 1;

	return ptr_entity;
}

void
__synapse_string_alloc_cleanup(__synapse_string_alloc_entity* pEntity)
{
	__synapse_string_alloc_block_node* ptr_seek
		= pEntity->backmost;

	for( ; pEntity->)
}

void
__synapse_string_alloc_allocate(__synapse_string_alloc_entity*, size_t);

void
__synapse_string_alloc_deallocate(__synapse_string_alloc_entity*);