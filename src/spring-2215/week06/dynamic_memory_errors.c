#include <stdlib.h>
#include <string.h>

struct person {
    char* name;
    unsigned int age;
};

int main() {
    // Example 1
    int *ptr = malloc(sizeof(int));

    // Example 2
    char my_str[] = "Hello";
    char *dup = malloc(strlen(my_str));
    free(dup);

    // Example 3
    struct person *p = malloc(sizeof(struct person));
    strcpy(p->name, "Collin");
    free(p);

    return 0;
}
