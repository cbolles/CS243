/**
 * file: structs_practice.c
 *
 * To compile to an executable:
 *      gcc -Wall -Wextra -pedantic -std=c99 -o structs_practice structs_practice.c
 *
 * To execute:
 *      ./structs_practice
 *
 * Defines a structure students that has a gpa, age, and name. Contained is functionality
 * to calculate the average gpa of the students.
 *
 * @author Collin Bolles
 */

#include <stdio.h>

/**
 * Represents a single student that has a gpa, age, and name.
 */
struct student_s {
    float gpa;
    int age;
    char name[20];
};

typedef struct student_s Student;

float get_average(Student students[], size_t num_students) {
    float total_gpa = 0;
    for(size_t i = 0; i < num_students; i++) {
        total_gpa += students[i].gpa;
    }
    return total_gpa / num_students;
}

int main() {
    // Create some students
    Student student_1 = { .gpa=3.5, .age=19, .name="Bobby" };
    Student student_2 = { .gpa=2.3, .age=20, .name="Sam" };

    // Put them in a list
    Student students[] = { student_1, student_2 };

    // Print out the average gpa
    printf("The average gpa was %f\n", get_average(students, 2));

    return 0;
}
