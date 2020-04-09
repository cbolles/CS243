#include <stdio.h>

struct my_struct {
    int value_one;
    char value_two[20];
};

int main() {
    struct my_struct example = { 10, "Bob" };
    printf("The sizeof my_struct is %lu\n", sizeof(example));

    return 0;
}
