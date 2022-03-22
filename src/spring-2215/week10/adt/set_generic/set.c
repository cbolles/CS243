#include <stdlib.h>
#include <stdbool.h>

#define STARTING_CAPACITY 10

struct set_s {
    void **content;
    size_t length;
    size_t capacity;

    int (*cmp)(void *, void*);

    void (*free_elem)(void *);
};

typedef struct set_s* Set;

#define _SET_IMPL_

#include "set.h"

Set new_set(int (*cmp)(void *, void *)) {
    Set set = (Set)malloc(sizeof(struct set_s));

    set->content = calloc(STARTING_CAPACITY, sizeof(void *));
    set->length = 0;
    set->capacity = STARTING_CAPACITY;
    set->cmp = cmp;

    return set;
}

void set_remove(Set set, void *elem) {
    for(size_t i = 0; i < set->length; i++) {
        if(set->cmp(set->content[i], elem) == 0) {
            for(size_t j = i + 1; j < set->length; j++) {
                set->content[j - 1] = set->content[j];
            }
            set->length--;
        }
    }
}

void set_insert(Set set, void *elem) {
    for(size_t i = 0; i < set->length; i++) {
        if(set->cmp(set->content[i], elem) == 0) {
            return;
        }
    }

    if(set->length == set->capacity) {
        set->content = realloc(set->content, sizeof(void *) * set->capacity * 2);
        set->capacity *= 2;
    }

    set->content[set->length] = elem;
    set->length++;
}

int set_contains(Set set, void *elem) {
    for(size_t i = 0; i < set->length; i++) {
        if(set->cmp(set->content[i], elem) == 0) {
            return 1;
        }
    }
    return 0;
}

void free_set(Set set) {

    for(size_t i = 0; i < set->length; i++) {
        set->free_elem(set->content[i]);
    }

    free(set->content);
    free(set);
}
