#include <stdio.h>
#include "person.h"

#define NUM_PEOPLE 4

int main() {
    struct person people_space[NUM_PEOPLE];
    Person people[NUM_PEOPLE];
    people[0] = &people_space[0];
    people[1] = &people_space[1];
    people[2] = &people_space[2];
    people[3] = &people_space[3];
    
    FILE *stream = fopen("person.save", "r");
    read_people(people, NUM_PEOPLE, stream);
    fclose(stream);

    for(int i = 0; i < NUM_PEOPLE; i++)
        print_person(people[i]);

    return 0;
}
