#include <stdio.h>


union s {
    int a;
    char b[4];
};


int main() {

    union s my_union;

    my_union.a = 0x11223344;

    printf("The value of a is 0x%08x\n", my_union.a);
    printf("The value stored in the char array is 0x%02x, 0x%02x, 0x%02x, 0x%02x\n",
            my_union.b[3], my_union.b[2], my_union.b[1], my_union.b[0]);

    my_union.b[0] = 0x00;

    printf("The value of a is 0x%08x\n", my_union.a);
    printf("The value stored in the char array is 0x%02x, 0x%02x, 0x%02x, 0x%02x\n",
            my_union.b[3], my_union.b[2], my_union.b[1], my_union.b[0]);

    return 0;
}
