/**
 * Here is a basic example of array usage. Try to find out what is printed out at each step.
 *
 * @author Collin Bolles
 */

#include <stdio.h> // printf
#include <stdlib.h> // size_t

void print_array(size_t size, int array[]) {
    for(size_t i = 0; i < size; i++)
        printf("array[%lu] = %d\n", i, array[i]);
}

int main() {
    
    // Uninitialized array
    int first_array[5];
    printf("First Array\n");
    print_array(5, first_array);

    // Array with first half of arrays populated
    int second_array[10] = { 1, 2, 3, 4, 5 };
    printf("Second Array\n");
    print_array(10, second_array);

    // Array with data initalized using a for loop
    int third_array[5];
    for(int i = 0; i < 5; i++) {
        third_array[i] = i * 2;
    }
    printf("Third Array\n");
    print_array(5, third_array);
    
    return 0;
}
