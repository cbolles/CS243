/**
 * Determining the size of structs is not necessarily straight forward. There are some details that
 * make determing the size a little difficult.
 *
 * @author Collin Bolles
 */

#include <stdio.h> // printf
#include <stdlib.h> // sizeof

struct struct_one {
    char a;
    int x;
};

struct struct_two {
    char name[10];
    int y;
};

int main() {
    printf("The size of struct_one is %lu\n", sizeof(struct struct_one));
    printf("The size of struct_two is %lu\n", sizeof(struct struct_two));

    return 0;
}
