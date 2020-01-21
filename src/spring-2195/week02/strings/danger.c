/**
 *
 * Lets see what are some of the dangers of working with C "strings".
 *
 * @author Collin Bolles
 */

#include <stdio.h>

int main() {
    // Lets say we have a situation where we want to add a bunch of letters to an array
    char str[10];
    str[0] = 'a';
    str[1] = 'b';

    // What would happen if I try to print str out?
    printf("The value of str is %s\n", str);

    // How do I fix this?
    return 0;
}
