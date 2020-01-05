#include <stdlib.h>

struct array_s {
    int *elements;
    size_t max_size;
};

#include "array.h"
#include <assert.h>

Array *create_array(size_t array_size) {
    Array *array = malloc(sizeof(Array));
    array->elements = calloc(array_size, sizeof(int));
    array->max_size = array_size;
    return array;
}

void set_element(Array *array, size_t index, int value) {
    assert(index < array->max_size);
    array->elements[index] = value;
}

int get_element(Array *array, size_t index) {
    assert(index < array->max_size);
    return array->elements[index];
}

void free_array(Array *array) {
    free(array->elements);
    free(array);
}
