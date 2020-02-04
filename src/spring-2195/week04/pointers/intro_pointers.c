/**
 * In C we have a concept of a "pointer". A pointer is another variable type. This time they store
 * addresses in memory with is something new. Below is an example of some code that uses pointer.
 * Try to draw out the memory diagram including the memory segments of the code and where the
 * pointers are pointing to.
 * 
 * @author Collin Bolles
 */

#include <stdio.h>

void print_change(char * my_var, char new_value) {
    printf("The value at address %p is being changed to %c\n", (void *)my_var, new_value);
}


void change_char(char * my_var, char new_value) {
    print_change(my_var, new_value);
    if(my_var != NULL)
        *my_var = new_value;

}


int main() {
    char my_char = 'A';
    change_char(&my_char, 'B');

    return 0;
}
