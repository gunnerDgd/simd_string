#pragma once
#include <string/allocation/details/bucket/string_alloc_bucket_type.h>

__synapse_string_alloc_bucket_node*
__synapse_string_alloc_bucket_node_retrieve
	(__synapse_string_alloc_bucket*, size_t);

__synapse_string_alloc_bucket_node*
__synapse_string_alloc_bucket_node_retrieve_front
	(__synapse_string_alloc_bucket*);

__synapse_string_alloc_bucket_node*
__synapse_string_alloc_bucket_node_retrieve_back
	(__synapse_string_alloc_bucket*);

void
__synapse_string_alloc_bucket_node_push
	(__synapse_string_alloc_bucket*, size_t, size_t);

void
__synapse_string_alloc_bucket_node_push_back
	(__synapse_string_alloc_bucket*, size_t);

void
__synapse_string_alloc_bucket_node_push_front
	(__synapse_string_alloc_bucket*, size_t);

void
__synapse_string_alloc_bucket_node_pop
	(__synapse_string_alloc_bucket*, size_t);

void
__synapse_string_alloc_bucket_node_pop_back
	(__synapse_string_alloc_bucket*);

void
__synapse_string_alloc_bucket_node_pop_front
	(__synapse_string_alloc_bucket*);