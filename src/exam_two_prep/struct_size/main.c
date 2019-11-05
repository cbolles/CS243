#include <stdio.h>

struct person_s {
    char favorite_letter;
    char *name; long id;
};

struct dog_s { 
    char *name;
    void (*bark)();
};

struct house_s {
    int number;
    char street_name [20];
    char owner_name [10];
};

int main() {
    printf("The size of a person is %lu\n", sizeof(struct person_s)); 
    printf("The size of a dog is %lu\n", sizeof(struct dog_s));
    printf("The size of a house is %lu\n", sizeof(struct house_s)); 
    return 0;
}
