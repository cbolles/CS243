/**
 * Enums are under the hood just ints. Enums are essentially just optional values.
 * Below is a basic example of using an enum.
 *
 * @author Collin Bolles
 */
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

enum gender {
    MALE,
    FEMALE,
    OTHER
};

struct person {
    char *name;
    unsigned int age;
    enum gender gender;
};

typedef struct person* Person;

Person new_person(char *name, unsigned int age, enum gender gender) {
    Person new_person = malloc(sizeof(struct person));
    
    new_person->name = malloc(strlen(name) + 1);
    strcpy(new_person->name, name);

    new_person->age = age;
    new_person->gender = gender;

    return new_person;
}

void free_person(Person person) {
    free(person->name);
    free(person);
}

void print_person(Person person) {
    printf("Name: %s\t Age: %d\t Gender: ", person->name, person->age);
    switch(person->gender) {
        case MALE:
            printf("MALE\n");
            break;
        case FEMALE:
            printf("FEMALE\n");
            break;
        default:
            printf("OTHER\n");
            break;
    }
}

int main() {
    Person person = new_person("Sam", 25, OTHER);
    print_person(person);
    free_person(person);

    return 0;
}
