#include <stdio.h>
#include "person.h"

int main() {
    struct person people[3];

    struct person person_one = {.first_name = "Bob", .last_name = "Smith", .age = 20};
    struct person person_two = {"Sam", "Will", 16};
    struct person person_three = {"Another", "Person", 20};

    people[0] = person_one;
    people[1] = person_two;
    people[2] = person_three;

    FILE *output_file = fopen("person.txt", "w");
    fwrite(people, 3, sizeof(struct person), output_file);

    fclose(output_file);
    return 0;
}
