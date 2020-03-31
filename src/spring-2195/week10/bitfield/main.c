#include <stdio.h>
#include <stdlib.h>

struct person {
    char *name;
    int age :7;
};

struct a {
    int x :4;
    int y :4;
};

void print_a(struct a my_struct) {
    printf("%d\n%d\n", my_struct.x, my_struct.y);
}

int main() {
    printf("Size of person: %lu\n", sizeof(struct person));
    printf("Size of a: %lu\n", sizeof(struct a));
    
    struct a my_struct = { 1, 2 };
    print_a(my_struct);

    my_struct.x = 250;
    print_a(my_struct);

    return 0;
}
