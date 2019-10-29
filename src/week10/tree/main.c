/**
 * file: main.c
 *
 * This is an example of how a user of an ADT can use the ADT without having to know how the ADT
 * is implemented. This makes using the data type easier to work with.
 *
 * @author Collin Bolles
 */

#include <stdio.h> // printf
#include "binary_tree.h"

/**
 * Defines the functionality to print a string that is stored in a void pointer
 * @param in The string to print out
 */
void print_string(void *in) {
    char *str = (char *)in;
    printf("%s ", str);
}

/**
 * Defines the functionality to print a number that is stored at a void pointer
 * @param in The int to print out
 */
void print_int(void *in) {
    int *num = (int *)in;
    printf("%d ", *num);
}

/**
 * Defines the functionality to print a decimal that is stored at a void pointer
 * @param in THe float to print out
 */
void print_float(void *in) {
    float *decimal = (float *)in;
    printf("%0.3f ", *decimal);
}


int main() {
    char *string = "Hello World";
    int my_num = 10;
    float decimal = 3.5;

    BinaryTree *left = create_tree((void*)string, NULL, NULL, print_string);
    BinaryTree *right = create_tree((void*)&decimal, NULL, NULL, print_float);
    BinaryTree *center = create_tree((void*)&my_num, left, right, print_int);

    // Prints the in order representation of the tree, note that we don't have to know how
    // to do in order printing with the tree, we just call this function
    print_tree(center);

    printf("\n");
    destroy_tree(center);

    return 0;
}
