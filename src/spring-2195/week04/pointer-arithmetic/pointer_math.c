/**
 * As we will see later on, much of what happens behind the scenes is centered around addresses, and
 * manipulating the data located at a given address. One of the fundamental tools for that is
 * pointer arithmetic. Below are some examples of using pointer arithmetic to access memeory in an
 * array.
 *
 * @author Collin Bolles
 */

#include <stdio.h>

void print_array(int size, int array[]) {
    printf("[ ");
    for(int i = 0; i < size - 1; i++) {
        printf("%d ", array[i]);
    }
    printf("%d ]\n", array[size - 1]);
}

void foo() {
    int data[5] = { 1, 2, 3, 4, 5 };
   
    printf("Original Array\n");
    print_array(5, data);

    // Modify the first element
    *(data + 0) = 2;

    // Modify the third element
    *(data + 2) = 6;

    printf("The modified array\n");
    print_array(5, data);

    // Go off the end of the array
    *(data + 5) = 100;
}


int main() {
    foo();
    return 0;
}
    
