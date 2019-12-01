#include <stdio.h> // printf
#include <string.h>
#include <stdlib.h>

enum grade_e {
    A = 90,
    B = 80,
    C = 70,
    D = 60,
    F = 0
};

typedef enum grade_e Grade;

struct professor_s {
    char * name;
    int age;
    Grade (*calculate_grade)(int[], int);
};

typedef struct professor_s Professor;

Grade calculate_grade(int grades[], int num_grades) {
    int total = 0;
    for(int i = 0; i < num_grades; i++)
        total += grades[i];
    int average = total / num_grades;

    if(average >= A)
        return A;
    if(average >= B)
        return B;
    if(average >= C)
        return C;
    if(average >= D)
        return D;
    else
        return F;
}

Professor *make_professor(char *name, int age) {
    Professor *prof = malloc(sizeof(prof));
    prof->name = malloc(strlen(name) + 1);
    strcpy(prof->name, name);
    prof->age = age;
    prof->calculate_grade = calculate_grade;
    return prof;
}

void free_professor(Professor *prof) {
    free(prof->name);
    free(prof);
}

char get_letter(Grade grade) {
    switch(grade) {
        case A:
            return 'A';
        case B:
            return 'B';
        case C:
            return 'C';
        case D:
            return 'D';
        default:
            return 'F';
    }
}

int main() {
    Professor *prof = make_professor("Bob", 25);
   
    int grades[] = { 100, 90, 80, 70 };
    Grade grade = prof->calculate_grade(grades, 4);
    printf("The student's average was a %c\n", get_letter(grade));

    free_professor(prof);

    return 0;
}
