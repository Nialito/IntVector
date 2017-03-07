#include <stdio.h>
#include "IntVector.h"
#define new_Line(); printf("\n");

int main(void)
{
	//
	IntVector *v = int_vector_new(3);
	//int_vector_free(v);
	printf("vector V = \npointer:%p\nsize:%d\ncapacity:%d\n", v->pointer, v->size, v->capacity);

	// TODO: replace with push_back
	/*
	for (int i = 0; i < v->capacity; i++) {
		int_vector_set_item(v, i, i + 1);
		v->size++;
		printf("%d\t", v->pointer[i]);
	}
	*/
	//
	for (int i = 0; i < 3; i++){
		int_vector_set_item(v, i, i + 1);
		printf("%d\t", int_vector_get_item(v, i));
	}
	//
	new_Line();
	printf("size of V after set_ item: %d", v->size);
	new_Line();
	
	//
	IntVector *a = int_vector_copy(v);
	printf("\nvector A = \npointer:%p\nsize:%d\ncapacity:%d\n", a->pointer, a->size, a->capacity);
	for (int i = 0; i < v->size; i++) {
		printf("%d\t", a->pointer[i]);
	}
	new_Line();
	new_Line();
	//
	int_vector_free(v);
	
	printf("vector V = \npointer:%p\nsize:%d\ncapacity:%d\n", v->pointer,v->size,v->capacity);
	printf("v: after free\n");
	for (int i = 0; i < v->size; i++) {		
		printf("%d\t", v->pointer[i]);
	}
	new_Line();
	
	int_vector_free(a);
	printf("a: after free\n");
	for (int i = 0; i < a->size; i++) {
		printf("%d\t", a->pointer[i]);
	}
	
	new_Line();

	printf("v:\n");
	for (int i = 0; i < v->size; i++) {
		int_vector_set_item(v, i, i + 1);
		printf("%d\t", int_vector_get_item(v, i));
	}
	
	new_Line();
	
	//
	printf("get_size v: %zu", int_vector_get_size(v));
	new_Line();
	//
	int_vector_push_back(v, 66);
	//
	printf("push_back v:\n");
	for (int i = 0; i < v->size; i++)
		printf("%d\t", int_vector_get_item(v, i));
	new_Line();
	printf("capacity: %d\n size: %d", v->capacity, v->size);
	new_Line();
	int_vector_pop_back(v);
	for (int i = 0; i < v->size; i++)
		printf("!%d\t", int_vector_get_item(v, i));
		new_Line();
	
	printf("shrink: %d", int_vector_shrink_to_fit(v));
	new_Line();
	printf("- %d", v->capacity);
	new_Line();
	
	printf("size = %d. capacity = %d.\n", v->size, v->capacity);
	printf("%d\n", int_vector_resize(v, 10));
	printf("size = %d. capacity = %d.\n", v->size, v->capacity);
	
}
