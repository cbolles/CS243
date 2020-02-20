#include <stdio.h>
#include "linked_list.h"

int main() {
    LinkedList_t list = new_linked_list();
    add(list, 1);
    add(list, 2);
    add(list, 3);
    add(list, 4);

    for(size_t i = 0; i < list_size(list); i++) {
        printf("list[%lu] = %d\n", i, get(list, i));
    }

    free_list(list);
    
    return 0;
}
