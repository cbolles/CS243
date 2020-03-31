#include <stdio.h>
#include "person.h"

#define NUM_PEOPLE 4

int main() {
    Person people[NUM_PEOPLE];

    people[0] = new_person("Bob", 20);
    people[1] = new_person("Sam", 21);
    people[2] = new_person("Matt", 13);
    people[3] = new_person("Kyle", 41);

    FILE *stream = fopen("people.save", "w");
    save_people(people, NUM_PEOPLE, stream);
    fclose(stream);

    return 0;
}
