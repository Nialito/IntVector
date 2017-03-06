#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "IntVector.h"
IntVector *int_vector_new(size_t initial_capacity)
{
	IntVector *v = malloc(sizeof(IntVector));
	v->pointer = malloc(initial_capacity * sizeof(int));
	v->size = 0;
	v->capacity = initial_capacity;
	return v;
}


IntVector *int_vector_copy(const IntVector *v)
{
	IntVector *a = malloc(sizeof(IntVector));
	a->pointer = malloc(v->capacity * sizeof(int));
	memcpy(a->pointer, v->pointer, sizeof(int) * v->capacity);
	a->size = v->size;
	a->capacity = v->capacity;
	return a;
}

void int_vector_free(IntVector *v)
{
	v->size = 0;
	v->capacity = 0;
	free(v->pointer);
	v->pointer = NULL;
	free(v);
}

int int_vector_get_item(const IntVector *v, size_t index)
{
	return v->pointer[index];
}

void int_vector_set_item(IntVector *v, size_t index, int item)
{
	if (index <= v->capacity)
		v->pointer[index] = item;
}

size_t int_vector_get_size(const IntVector *v)
{
	return v->size;
}

size_t int_vector_get_capacity(const IntVector *v)
{
	return v->capacity;
}

int int_vector_push_back(IntVector *v, int item)
{
	if (v->size < v->capacity){
		v->pointer[v->size + 1] = item;
		v->size++;
	}
	else {
		v->capacity *= 2;
		v->pointer = realloc(v->pointer, v->capacity * sizeof(int));
		if (v->pointer == NULL)
			return -1;
		v->pointer[v->size] = item;
		v->size++;
	}
	return 0;
}

void int_vector_pop_back(IntVector *v)
{
	if (v->size != 0) {
		v->size--;
		v->pointer[v->size] = 0;
	}
}

int int_vector_shrink_to_fit(IntVector *v)
{
	if (v->size < v->capacity) {
		v->capacity = v->size;
		v->pointer = realloc(v->pointer, v->size * sizeof(int));
		return 0;
	}
	return -1;
}
int int_vector_resize(IntVector *v, size_t new_size)
{
	if (new_size == v->size)
		return 0;
	if (new_size > v->size) {
		v->pointer = realloc(v->pointer, new_size * sizeof(int));
		if (v->pointer == NULL)
			return -1;
		for (int i = new_size - v->size; i < new_size; i++)
			v->pointer[i] = 0;
	} else if (new_size < v->size) {
		return int_vector_shrink_to_fit(v);
	}
	v->size = new_size;
	int_vector_reserve(v, new_size);
	return 0;
}

int int_vector_reserve(IntVector *v, size_t new_capacity)
{
	if (new_capacity > v->capacity) {
		v->capacity = new_capacity;
		return 0;
	}
	return -1;
}

