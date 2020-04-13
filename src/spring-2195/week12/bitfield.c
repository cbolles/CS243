#include <stdio.h>


/**
 *  Bit 0: Flag
 *  Bit 1: Flag
 *  Bit 2, 3, 4, 5: 4 bit value
 * 
 */
struct my_packed {
    unsigned int a  :1;
    unsigned int b  :1;
    int c           :4;
    int d           :4;
    int e           :8;
    int reserved    :12;
};

union my_union {
    struct my_packed packed;
    int my_num;
};

int main() {
    struct my_packed example;
    printf("a is %d\n", example.a);
    printf("The size of my_packed is %lu\n", sizeof(struct my_packed));
    return 0;
}
