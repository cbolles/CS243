/**
 * file: pointer_arithmetic.c
 *
 * In class we saw how pointers and arrays work in a very similar way, that is because arrays work
 * using pointer arithmetic. This code provides and example of how pointer arithemtic works.
 *
 * @author Collin Bolles
 */
#include <stdio.h> // printf
#include <stdlib.h> // malloc, calloc

int main() {
    // Lets make a pointer that points to an array of ten integers
    int *my_array = calloc(10, sizeof(int));

    // Put in some test data
    my_array[0] = 5;
    my_array[1] = 6;
    my_array[5] = 10;

    // Lets look at where my_array points to
    printf("The pointer my_array points to %p\n", (void *)my_array);

    // Now lets look at the address of the first index in my_array
    printf("The address of my_array[0] is %p\n", (void *)&my_array[0]);

    // What do we notice about the output of the first two print statements?
    
    // Lets get the address of the element in my array
    int *second_element = &my_array[1];
    printf("The address of my_array[1] is %p\n", (void *)second_element);

    // What do we notice about the difference between the address of index 0 vs index 1?
    printf("The difference between the address of my_array[0] and my_array[1] is %lu\n", 
            (long)&my_array[1] - (long)&my_array[0]);

    // What is the significance of the difference between the two? What if my_array is an array of longs?
    
    // Lets try manually working with pointer arithmetic
    
    // Represents the memory as simply numbers
    long location_0 = (long)my_array;
    // Add the size of an integer to the first location in my_array
    long location_1 = location_0 + sizeof(int);

    // Turn the number into a pointer
    int *location_1_ptr = (int *)location_1;

    // Print out what is stores in memory at location_1
    printf("The value at my_array[1] is %d\n", *location_1_ptr); 

    // What about getting the fifth element?
    long location_4 = location_0 + sizeof(int) * 5;
    int *location_4_ptr = (int *)location_4;

    printf("The value at my_array[4] is %d\n", *location_4_ptr);

    // What if I want the tenth element?
    return 0;
}
