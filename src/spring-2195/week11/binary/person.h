/**
 * Header that provides tools for reading and writing a person to a file. Provides the person
 * struct and the functionality associated with person.
 *
 * @author Collin Bolles
 */

#ifndef PERSON_H
#define PERSON_H
#include <stdio.h>
struct person {
    char name[20];
    int age;
};

typedef struct person* Person;

Person new_person(char * name, int age);

void free_person(Person person);

void save_people(Person people[], size_t num_people, FILE *stream);

void read_people(Person people[], size_t num_people, FILE *stream);

void print_person(Person person);
#endif
