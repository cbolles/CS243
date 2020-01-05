/**
 * file: packed.c
 *
 * This example shows how you can unpack data using bitwise operations
 *
 * @author Collin Bolles
 */
#include <stdio.h>

int main() {
    short int original_number = 16705;

    char bottom_half = original_number & 0xff;
    char top_half = original_number >> 8;

    printf("The original number was %d\n", original_number);
    printf("The bottom half of the number is represented as %d\n", bottom_half);
    printf("The top half of the number is represented as %d\n", top_half);

    printf("The characters contained is %c in the top and %c in the botton\n", top_half, bottom_half);

    return 0;
}
