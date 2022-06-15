#pragma once
#include <stdalign.h>
#include <xmmintrin.h>

typedef struct __synapse_string_alloc_block
{
	__m128 block[8];
} __synapse_string_alloc_block;

typedef struct __synapse_string_alloc_block_node
{
	__synapse_string_alloc_block	  *ptr_block;
	__synapse_string_alloc_block_node *prev, 
									  *next;
} __synapse_string_alloc_block_node;

typedef struct __synapse_string_alloc_entity
{
	__synapse_string_alloc_block_node
		* entry	   ,
		* frontmost,
		* backmost ;

	size_t
		alloc_count,
		used_count ;
} __synapse_string_alloc_entity;