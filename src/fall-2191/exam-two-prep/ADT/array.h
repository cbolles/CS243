#ifndef ARRAY_H
#define ARRAY_H
#include <stdlib.h> // size_t

typedef struct array_s Array;

Array *create_array(size_t array_size);

void set_element(Array *array, size_t index, int value);

int get_element(Array *array, size_t index);

void free_array(Array *array);
#endif
