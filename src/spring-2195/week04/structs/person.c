/**
 * Structures are groups of related variables put together. This is similar to named tuples in
 * python. Unlike classes, there is no concept of a "self" or "this", there is no inheritance, and
 * we don't have methods. This is a basic example of how to make a struct.
 *
 * @author Collin Bolles
 */

#include <stdio.h>

#define MAX_NAME_LENGTH 20


struct person_s {
    int age;
    char first_name[MAX_NAME_LENGTH];
    char last_name[MAX_NAME_LENGTH];
};

void print_person(struct person_s person) {
    printf("First Name: %s, Last Name: %s, Age: %d\n", person.first_name, person.last_name, person.age);
}

int main() {
    struct person_s me = { 20, "Collin", "Bolles" };
    print_person(me);

    // What are some other differences you notice between structs and classes?
    return 0;
}
