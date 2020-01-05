#include <stdio.h> // printf
#include <string.h>
#include <stdlib.h>

typedef struct person_s {
    char *name;
    int id;
    char *address;
} Person;

Person *create_person(char *name, int id, char *address) {
    Person *person = malloc(sizeof(Person));
    
    person->name = malloc(strlen(name) + 1);
    strcpy(person->name, name);
    
    person->id = id;

    person->address = malloc(strlen(address) + 1);
    strcpy(person->address, address);
    return person;
}

void free_person(Person *person) {
    free(person->name);
    free(person->address);
    free(person);
}

Person *copy_person(Person *original) {
    Person *person = create_person(original->name, original->id, original->address);
    return person;
}

void print_person(Person *person) {
    printf("%s has an id %d and lives at %s\n", person->name, person->id, person->address);
}

int main() {
    Person *first = create_person("Bob", 1, "1 Lomb Drive");
    Person *second = copy_person(first);

    print_person(first);
    free_person(second);

    print_person(second);
    free_person(second);

    return 0;
}

