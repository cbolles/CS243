#include <stdio.h>

struct Person {
    char name[20];
    int age;
};

void addYear(int *age) {
    (*age)++;
}

int main() {
    struct Person Paul = {"Paul", 10};
    addYear(&Paul.age);
    printf("Paul is %d years old\n", Paul.age);
    return 0;
}
