/**
 * file: weird_arrays.c
 * 
 * To compile to an executable:
 *      gcc -Wall -Wextra -pedantic -std=c99 -o weird_arrays weird_arrays.c
 * 
 * To run:
 *      ./weird_arrays
 * 
 * C is known for not giving you the safety nets that other languages have and that is
 * DEFINITELY true for arrays. When you learn more about pointers in class, you will
 * get more of an understanding why.
 * 
 * For now, here are some weird things about arrays that you might run into when writing
 * your homeworks.
 * 
 * @author Collin Bolles
 */
#include <stdio.h> // printf

int main() {
    /*
     * When working with most languages, new arrays are all assigned zero. That is not
     * the case with C. The contents of the array could be anything! In homework
     * assignments if you forget to give the array values, weird things can happen.
     * 
     * Run multiple times and the values of the array can change  
     */
    int first_array[5];

    for(int i = 0; i < 5; i++) {
        printf("first_array[%d] = %d\n", i, first_array[i]);
    }

    /*
     * Another thing that doesn't exist out of the box is "index out of bounds". You
     * can index "basically" whatever you want.
     */
    int second_array[] = {1, 2, 3};
    for(int i = 0; i < 10; i ++) {
        printf("second_array[%d] = %d\n", i, second_array[i]);
    }

    /*
     * The closest thing you will see to an "index out of bounds" is a seg fault,
     * basically you tried to access data you shouldn't have. You will get this error
     * A LOT
     */
    for(int i = 0; i < 100000; i++) {
        printf("second_array[%d] = %d\n", i, second_array[i]);
    }

    return 0;
}
