/**
 * file: half_pointer.c
 *
 * The following example shows how we can start attempting to get an integer half way through
 * an existing integer.
 *
 * @author Collin Bolles
 */
#include <stdio.h>

int main() {
    int my_num = 7;
    int *my_ptr = &my_num;

    long my_location = (long)my_ptr;
    my_location+=2;

    int *half_ptr = (int *)my_location;

    printf("The original address was %p\n", my_ptr);
    printf("The new address is %p\n", half_ptr);
    printf("The num at the new address is %d\n", *half_ptr);

    return 0;
}
