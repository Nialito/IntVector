#include <stdio.h>
#include "IntVector.h"

int main()
{
	IntVector *v = int_vector_new(3);
	printf("vector V = \npointer:%p\nsize:%d\ncapacity:%d\n", v->pointer,v->size,v->capacity);
	
	IntVector *a = int_vector_copy(v);
	printf("\nvector A = \npointer:%p\nsize:%d\ncapacity:%d\n", a->pointer,a->size,a->capacity);
	
	int_vector_free(v);
	printf("vector V = \npointer:%p\nsize:%d\ncapacity:%d\n", v->pointer,v->size,v->capacity);
	
	return 0;
}
