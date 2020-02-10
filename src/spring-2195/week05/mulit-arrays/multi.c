/**
 * As we talked about earlier in class, array access is under the hood just pointer arithmetic. 
 * So how can we use pointer arithmetic in a multidimensional array?
 *
 * @author Collin Bolles
 */

#include <stdio.h>

#define NUM_ROWS 3
#define NUM_COLS 3

void print_multi_array(int my_array[NUM_ROWS][NUM_COLS]) {
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            printf("%d ", my_array[i][j]);
        }
        printf("\n");
    }
}

void print_divide() {
    printf("**********\n");
}

int main() {
    // Create a two-dimensional array and populate it
    int count = 0;
    int my_array[NUM_ROWS][NUM_COLS];
    for(int i = 0; i < NUM_ROWS; i++) {
        for(int j = 0; j < NUM_COLS; j++) {
            my_array[i][j] = count++;
        }
    }
    printf("Original Array\n");
    print_multi_array(my_array);
    print_divide();

    // Get the address as an unsigned long
    unsigned long base_address = (long)&my_array[0][0];
    printf("The first element is located at address %p\n", (void *)base_address);

    // How do we print 1,0?
    unsigned long address_row_1 = base_address + sizeof(int) * NUM_COLS;
    unsigned long address_1_0 = address_row_1 + sizeof(int) * 0;
    printf("The address of (1,0) is %p and the value is %d\n", (void *)address_1_0, *(int *)address_1_0);
    
    // How to print 2,2?
    unsigned long address_row_2 = base_address + 2 * (sizeof(int) * NUM_COLS);
    unsigned long address_2_2 = address_row_2 + 2 * sizeof(int);
    printf("The address of (2,2) is %p and the value is %d\n", (void *)address_2_2, *(int *)address_2_2);
    return 0;
}

