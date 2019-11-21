#include <stdio.h>
#include "person.h"

int main() {
    FILE *person_file = fopen("person.txt", "r");
    struct person people[3];
    fread(people, sizeof(struct person), 3, person_file);
    for(int i = 0; i < 3; i++) {
        printf("%s %s age: %d\n", people[i].first_name, people[i].last_name, people[i].age);
    }
    fclose(person_file);
    return 0;
}
