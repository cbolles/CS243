/**
 * file: passing_by_reference.c
 *
 * In C everything is technically passed by value. That is to say that each time you pass a value
 * into a function, the function is getting a copy of that value. We get around that by using
 * pointers.
 *
 * A pointer points to a value, so if we pass in a pointer to a function, the function can follow
 * the pointer to a value allowing us to change the actual value not just the copy.
 *
 * This example shows how we can modify a list of structures using pointers.
 *
 * @author Collin Bolles
 */
#include <stdio.h> // printf

struct person_s {
    char name[20];
    int age;
};

typedef struct person_s * Person;

/**
 * Takes in a person whose age is incremented
 * @param person The person to increment their age
 */
void add_year(Person person) {
    (*person).age++;
}

/**
 * Helper function to print out the information stored in person
 * @param person Pointer to a person
 */
void print_person(Person person) {
    printf("Name: %s, Age: %d\n", person->name, person->age);
}

int main() {
    // Create person struct
    struct person_s my_person = {.name="Bob", .age=22}; 
    
    // Create a pointer to my person
    Person bob = &my_person;

    // Print out the original state of the person
    print_person(bob);

    add_year(bob);

    // Print out the new state of the person
    print_person(bob);

    return 0;
}
