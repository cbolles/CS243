#include <stdio.h>

struct person_s {
    char favorite_letter;
    char *name;
    char *address;
    float gpa;
};

int main() {
    printf("The size of a person is %lu\n", sizeof(struct person_s));
    return 0;
}
