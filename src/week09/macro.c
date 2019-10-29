#include<stdio.h>

struct Person {
    char *name;
    int id;
    int age;
};

#define MAKE_PERSON(a, b, c) {a, b, c}

int main() {
    struct Person person = MAKE_PERSON("Collin", 10, 10);
    struct Person another = MAKE_PERSON("Bob", 7, 16);
    printf("%d\n", person.age);

    return 0;
}
