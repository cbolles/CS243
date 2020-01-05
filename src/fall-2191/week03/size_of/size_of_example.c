/**
 * 
 * file: size_of_example.c
 *
 * To compile and execute:
 *      gcc -Wall -Wextra -pedantic -std=c99 -o size_of_example size_of_example.c
 *
 * To exexute:
 *      ./size_of_example
 *
 * Some examples of size of. The size of is the number of bytes that are needed.
 *
 * @author Collin Bolles
 */

#include <stdio.h> //printf

int main() {
    char hello[] = "Hello";
    printf("The size if hello is %lu\n", sizeof(hello));
    printf("The size of an int is %lu\n", sizeof(int));

    int nums[] = {1, 2, 3};
    printf("The size of nums is %lu\n", sizeof(nums));
    
    size_t len_nums = sizeof(nums) / sizeof(int); // The total number of bytes divided the number of bytes per element
    printf("The number of elements in nums is %lu\n", len_nums);

    return 0;
}
