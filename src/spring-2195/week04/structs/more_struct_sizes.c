#include <stdio.h>
#include <stdlib.h>

struct a {
    int x;
    char y[2];
};

struct b {
    char x;
    char y[14];
};

struct c {
    int x[6];
    long y;
    char z;
};

int main() {
    printf("sizeof(struct a) = %lu\n", sizeof(struct a));
    printf("sizeof(struct b) = %lu\n", sizeof(struct b));
    printf("sizeof(struct c) = %lu\n", sizeof(struct c));

    return 0;
}
