#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "person.h"

Person new_person(char *name, int age) {
    Person new_person = malloc(sizeof(struct person));
    strcpy(new_person->name, name);
    new_person->age = age;
    return new_person;
}

void free_person(Person person) {
    free(person);
}

void save_people(Person people[], size_t num_people, FILE *stream) {
    for(size_t i = 0; i < num_people; i++)
        fwrite(people[i], sizeof(struct person), 1, stream);
}

void read_people(Person people[], size_t num_people, FILE *stream) {
    for(size_t i = 0; i < num_people; i++)
        fread(people[i], sizeof(struct person), 1, stream);
}

void print_person(Person person) {
    printf("Name: %s, Age: %d\n", person->name, person->age);
}
