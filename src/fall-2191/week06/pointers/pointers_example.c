/**
 * file: pointers_example.c
 *
 * To compile to an executable:
 *      gcc -Wall -Wextra -pedantic -std=c99 -o pointers_example pointers_example.c
 *
 * To execute:
 *      ./pointers_example
 *
 * This file includes a basic example of using pointers. Pointers are variables that store
 * addresses which "point" to other data. They are defined similar to other variables with a single
 * difference.
 *      int *my_point;
 * In the example above, I am creating a pointer that will point to an int and I am not assigning
 * a value to the pointer. In the code block we will go into more examples of using pointers
 * @Collin Bolles
 */
#include <stdio.h> // printf

int main() {
    // A regular integer variable
    int a = 7;
    // A pointer that holds the address of a. & is an operator that says "get the address of"
    int *a_ptr = &a;

    // Print the address stored by a_ptr, then "dereference" a_ptr to get the value at the address
    printf("The value stored at %p is %d\n", (void*)a_ptr, *a_ptr);

    // When I dereference a pointer, I can modify the value at that address
    *a_ptr = 10;

    // Notice how a has changed here
    printf("The value stored  at %p has been changed to %d\n", (void*)a_ptr, a);

    // We can have pointers that point to anything, including another pointer
    int **a_ptr_ptr = &a_ptr;
    
    // The above line says "make a pointer to an int pointer that has the address of a_ptr"
    printf("The pointer at address %p points to %d\n", (void*)a_ptr_ptr, **a_ptr_ptr);

    // We can make another pointer that points to a, and use that new pointer to modify a
    int *another_ptr = &a;
    *another_ptr = 7;

    printf("The value stored at %p was changed to %d\n", (void*)another_ptr, a);


    // a_ptr points to a, so if we dereference a_ptr we get the changed value of a
    printf("The value stored in a_ptr is now %d\n", *a_ptr);

    return 0;
}
