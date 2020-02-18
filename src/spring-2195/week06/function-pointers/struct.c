/**
 * Function pointers work like any other variable. This includes the ability to store them in
 * structs. This gives the apperance that struct have methods, what is the difference between having
 * a function pointer and having a method?
 * @author Collin Bolles
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct person {
    char *name;
    int age;
    short (*equals)(struct person *, struct person *);
};

typedef struct person person_s;
typedef struct person * person_t;

/**
 * Check if two people are equal by comparing their name and age
 */
short equals(person_t person_one, person_t person_two) {
    return strcmp(person_one->name, person_two->name) == 0 && person_one->age == person_two->age;
}

/**
 * Allocates space for a new person
 */
person_t new_person(char *name, int age) {
    person_t new_person = malloc(sizeof(person_s));
    new_person->name = malloc(strlen(name) + 1);
    strcpy(new_person->name, name);
    new_person->age = age;
    new_person->equals = equals;
    return new_person;
}

/**
 * Frees the dynamically allocated space for a person including their name
 */
void free_person(person_t person) {
    free(person->name);
    free(person);
}

int main() {
    // Create three people
    person_t person_one = new_person("Bob", 21);
    person_t person_two = new_person("Bob", 21);
    person_t person_three = new_person("Sam", 31);

    printf("Person one equals person two %d\n", person_one->equals(person_one, person_two));
    printf("Person one equals person three %d\n", person_one->equals(person_one, person_three));

    // Free the dynamic memory of the people
    free(person_one);
    free(person_two);
    free(person_three);

    return 0;
}
