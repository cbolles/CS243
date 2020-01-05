/**
 * file: packed_struct.c
 *
 * The following shows two different structs that each take different sizes.
 *
 * @author Collin Bolles
 */
#include <stdio.h>

enum student_year {
    FIRST,
    SECOND,
    THIRD,
    FOURTH,
    FIFTH
};

struct student_one {
    int age;
    enum student_year year;
    char favorite_letter;
};

struct student_two {
    int age:8;
    enum student_year year:8;
    char favorite_letter:8;
};

int main() {
    printf("The size of the original struct is %lu\n", sizeof(struct student_one));
    printf("The size of the packed struct is %lu\n", sizeof(struct student_two));
    return 0;
}
