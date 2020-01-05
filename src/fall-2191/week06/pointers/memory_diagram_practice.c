/**
 * file: memory_diagram_practice.c
 *
 * To compile to an executable:
 *      gcc -Wall -Wextra -pedantic -std=c99 -o memory_diagram_practice memory_diagram_practice.c
 * 
 * To execute:
 *      ./memory_diagram_practice
 *
 * Memory diagrams can be used to represents points graphically. This makes things easier when we
 * want to wrap our heads around what is actually happening with the memory, were points are
 * pointing too, etc. For example lets say we have the following code snippet.
 *
 * int example = 8;
 * int *my_ptr = &example;
 *
 * The memory diagram would look something like this.
 *
 *                ___________
 * my_ptr ------>|example | 8|
 *                -----------
 * 
 * Basically we shows pointers as arrows to what they point to and other varaibles as what they
 * store. Try to draw a memory diagram for the following code.
 *
 * @author Collin Bolles
 */

int main() {
    
    int a = 8;
    int *a_ptr = &a;
    
    int b = 10;
    int *b_ptr = &b;

    int **b_ptr_ptr = &b_ptr;

    *a_ptr = 5;

    return 0;
} 
