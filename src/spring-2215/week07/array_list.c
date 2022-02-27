#include <stdio.h>
#include <stdlib.h>

struct list_s {
    int *contents;
    size_t length;
    size_t capacity;
};

typedef struct list_s List;

List *new_list() {
    List *new_list = malloc(sizeof(List));

    new_list->contents = malloc(5 * sizeof(int));
    new_list->length = 0;
    new_list->capacity = 5;

    return new_list;
}

int list_get(List *self, size_t index) {
    return self->contents[index];
}

void list_append(List *self, int new_elem) {
    // Space is in array
    if(self->length >= self->capacity) {
        self->contents = realloc(self->contents, self->capacity * 2 * sizeof(int));
        self->capacity *= 2;
    }
    self->contents[self->length] = new_elem;
    self->length++;
}

void list_free(List *self) {
    free(self->contents);
    free(self);
}

void list_insert(List *self, size_t index, int elem) {
    // Check to see if we are at capacity
    // Yes => realloc with more memory
    // Shift elements down
    // insert
}

int main() {

    List *lst = new_list();
    list_append(lst, 1);
    list_append(lst, 2);
    list_append(lst, 3);

    for(int i = 0; i < 3; i++) {
        printf("lst[%d] = %d\n", i,list_get(lst, i));
    }

    list_free(lst);

    return 0;
}

