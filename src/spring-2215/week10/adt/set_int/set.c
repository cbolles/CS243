#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>

#define _SET_IMPL_

struct set_s {
    int *elements;
    size_t length;
    size_t capacity;
};

typedef struct set_s* Set;

#include "set.h"

/**
 * Helper function to get the index of an element in the set.
 *
 * @param set The set to search throught
 * @param element The element to search through
 * @return The index in the set of the element or -1
 */
static bool find(Set set, int element, size_t *result) {
    for (size_t i = 0; i < set->length; i++) {
        if (set->elements[i] == element) {
            *result = i;
            return true;
        }
    }
    return false;
}

Set new_set() {
    Set set = malloc(sizeof(struct set_s));
    set->elements = calloc(sizeof(int), 5);
    set->length = 0;
    set->capacity = 5;

    return set;
}

size_t length(Set set) {
    return set->length;
}

void add(Set set, int element) {
    if (contains(set, element)) {
        return;
    }

    set->elements[set->length] = element;
    set->length++;

    if (set->length == set->capacity) {
        set->elements = realloc(set->elements, sizeof(int) * set->capacity * 2);
        set->capacity *= 2;
    }
}

void set_remove(Set set, int element) {
    size_t index;
    if (!find(set, element, &index)) {
        return;
    }

    // Shift elements down
    for (size_t i = index + 1; i < set->length; i++) {
        set->elements[i - 1] = set->elements[i];
    }

    set->length--;
}

bool contains(Set set, int element) {
    size_t index;
    return find(set, element, &index);
}

void free_set(Set set) {
    free(set->elements);
    free(set);
}

void print_set(Set set) {
    printf("Set of size %lu: {", set->length);
    for (size_t i = 0; i < set->length; i++) {
        printf("%d, ", set->elements[i]);
    }
    printf("}\n");
}
