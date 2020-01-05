#include <stdio.h>

union ex {
    int num;
    char c;
};

int main() {
    union ex my_union;
    my_union.num = 65;
    printf("The size of union ex is %lu\n", sizeof(union ex));
    printf("The char in my_union is %c\n", my_union.c);
    my_union.c = 'B';
    printf("The int in my_union is %d\n", my_union.num);
}
