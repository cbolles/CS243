/**
 * file: even_odd.c
 *
 * The following is an example of determining if a number is even or odd using only bitwise
 * operations.
 * @author Collin Bolles
 */
#include <stdbool.h>
#include <stdio.h>

bool is_even(unsigned int num) {
    return !(num & 1);
}

int main() {
    for(unsigned int i = 0; i < 10; i++) {
        if(is_even(i))
            printf("%d is even\n", i);
        else
            printf("%d is odd\n", i);
    }
    return 0;
}
