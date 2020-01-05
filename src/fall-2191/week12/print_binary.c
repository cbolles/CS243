/**
 * file: print_binary.c
 *
 * The following is an example of how to print out a number in binary using bitwise operators.
 *
 * @author Collin Bolles
 */
#include <stdio.h>

void print_number(int num) {
    printf("%d in binary is: ", num);

    for(int i = sizeof(num) * 8 - 1; i >= 0; i--) {
        if(i % 8 == 0 && i != 0)
            printf(" ");
        char bit = (num >> i) & 1;
        printf("%d", bit);
    }
    printf("\n");
}

int main() {
    print_number(1);
    print_number(123456);
    print_number(-1927472);
    return 0;
}
