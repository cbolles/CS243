#include <stdio.h> // printf
#include <stdlib.h> // malloc
#include <stdbool.h>
#include <string.h>

struct student_s {
    char *name;
    int age;
    float gpa;
    bool (*equal)(struct student_s *, struct student_s *);
};

typedef struct student_s Student;

bool student_equal(Student *student_1, Student *student_2) {
    bool equal_names = strcmp(student_1->name, student_2->name) == 0;
    bool equal_age = student_1->age == student_2->age;
    bool equal_gpa = student_1->gpa == student_2->gpa;
    return equal_names && equal_age && equal_gpa;
}

Student *create_student(char *name, int age, float gpa) {
    Student *student = malloc(sizeof(Student));
    student->name = malloc(strlen(name) + 1);
    strcpy(student->name, name);
    student->age = age;
    student->gpa = gpa;
    student->equal = student_equal;
    return student;
}

void free_student(Student *student) {
    free(student->name);
    free(student);
}

int main() {
    Student *student_1 = create_student("Bob", 19, 3.5);
    Student *student_2 = create_student("Sam", 20, 4.0);
    Student *student_3 = create_student("Bob", 19, 3.5);

    if(student_1 ->equal(student_1 , student_2))
        printf("Student 1 and Student 2 are equal\n");
    if(student_1 ->equal(student_1 , student_3))
        printf("Student 1 and Student 3 are equal\n");
    
    free(student_1);
    free(student_2);
    free(student_3);
    
    return 0;
}
