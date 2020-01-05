/**
 * file: good_memory.c
 *
 * To compile to an executable:
 *      gcc -Wall -Wextra -pedantic -std=c99 -o good_memory good_memory.c
 *
 * To execute and test with valigrind:
 *      valgrind --leak-check=full ./good_memory
 *
 * This correctly makes use of dynamic memory by allocating then deallocating memory as we go.
 *
 * @author Collin Bolles
 */
#include <stdio.h> // printf
#include <stdlib.h> // malloc, free

int main() {
    int *my_number = malloc(sizeof(int)); // Allocate enough storage to keep an int
    *my_number = 5; // Assign the value of the dereferenced my_number to 5;

    printf("My point points to the value %d\n", *my_number);

    free(my_number); // I am done with my number so I will free it
    return 0;
}
