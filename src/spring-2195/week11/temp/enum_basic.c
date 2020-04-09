#include <stdlib.h>
#include <string.h>
#include <stdio.h>

enum level {
    UNDERGRAD = 1,
    GRAD = 2,
    DR = 3
};

struct student {
    char *name;
    unsigned int age;
    enum level student_level;
};

typedef struct student *Student;

Student new_student(char *name, unsigned int age, enum level student_level) {
    Student new_student = malloc(sizeof(struct student));
    
    new_student->name = malloc(strlen(name) + 1);
    strcpy(new_student->name, name);

    new_student->age = age;
    new_student->student_level = student_level;
    return new_student;
}

void free_student(Student student) {
    free(student->name);
    free(student);
}

void print_student(Student student) {
    printf("Name: %s Age: %d Level: ", student->name, student->age);

    switch(student->student_level) {
        case UNDERGRAD:
            printf("UNDERGRAD\n");
            break;
        case GRAD:
            printf("GRAD\n");
            break;
        case DR:
            printf("DR\n");
            break;
    }

    printf("%d\n", student->student_level);
}

int main() {
    Student student = new_student("Bob", 20, UNDERGRAD);
    print_student(student);
    free_student(student);

    return 0;
}
