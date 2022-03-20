#include "set.h"
#include <stdio.h>

int main() {
    Set set = new_set();

    add(set, 1);
    printf("Set contains 1: %d\n", contains(set, 1));

    add(set, 2);
    add(set, 3);
    add(set, 1);
    print_set(set);

    set_remove(set, 1);
    print_set(set);

    free_set(set);
}
