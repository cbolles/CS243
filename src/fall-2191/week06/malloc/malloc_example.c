/**
 * file: malloc_example.c
 *
 * Dynamic memory is at the heart of C programming and is considered one of the most dangerous
 * elements of C. There is a reason you do not call malloc in Java or Python. Malloc simply is
 * used to create a subsection of memory in the Heap with which we can put whatever we want in it.
 * Note that C will assume you know what you are doing, everytime we allocate memory, we also
 * have to free the memory.
 *
 * @author Collin Bolles
 */
#include <stdio.h> // printf
#include <stdlib.h> // malloc, free, calloc

int main() {
    // Create a pointer to some space that can hold a character
    char *my_character = malloc(sizeof(char));
    *my_character = 'A';

    printf("The character stored at %p is %c\n", (void*)my_character, *my_character);

    // Each time we call malloc we need to call free
    free(my_character);

    // NOTE WE CANNOT USE MY_CHARACTER AGAIN UNLESS WE REASSIGN IT OTHERWISE PROBLEMS!!
    
    // Lets make a dynamically created array of numbers
    int *my_array = calloc(10, sizeof(int));;

    my_array[0] = 10;
    for(int i = 0; i < 10; i++) {
        printf("my_array[%d] = %d\n", i, my_array[i]);
    }
    
    // Have to call free again
    free(my_array);

    return 0;
}
