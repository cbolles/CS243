/**
 * file: basic_arrays.c
 * 
 * To compile to an executable:
 *      gcc -Wall -Wextra -pedantic -std=c99 -o basic_arrays basic_arrays.c
 * 
 * To run:
 *      ./basic_arrays
 * 
 * Here are some of the basic of an array, creating one, indexing the array, etc. Much
 * of this should look familiar to you.
 * 
 * @author Collin Bolles
 */
#include <stdio.h> // printf

int main() {
    int my_array[5]; // Create an array of ints with 5 elements
    my_array[0] = 6; // Set the first element to 6
    my_array[1] = 3; // Set the second element to 3
    my_array[0] = 4; // Change the value of the first element to 4

    printf("The first element of my_array is %d\n", my_array[0]);
    printf("The second element of my_array is %d\n", my_array[1]);

    int another_array[] = { 4, 5, 1, 3 }; // Create an array with predefined values
    for(int i = 0; i < 4; i++) { // Note, we cannot directly get the size of the array
        printf("another_array[%d] = %d\n", i, another_array[i]); // Print out each element in the array
    }

    return 0; // All good
}
