/**
 * file: palindrome.c
 *
 * Checks to see if the binary representation of a number is a palindrome, uses chars for
 * simplicity.
 * @author Collin Bolles
 */
#include <stdio.h>
#include <stdbool.h>

bool is_palindrome(unsigned char input) {
    for(int i = 0; i < 4; i++) {
        char left_bit = input >> i & 1;
        char right_bit = input >> (7 - i) & 1;
        if(left_bit != right_bit)
            return false;
    }
    return true;
}

int main() {
    for(unsigned char i = 0; i < 255; i++) {
        if(is_palindrome(i))
            printf("The value of %d is a palindrome in binary\n", i);
    }
    return 0;
}
