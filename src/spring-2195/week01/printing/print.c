/**
 * file: print.c
 *
 * Printing in C is in a lot of ways not very different from Java or Python. The biggest difference
 * is when you want to print out variables.
 *
 * Python
 * x = 7
 * print('X is ' + str(x))
 *
 * In C we have "format strings" which are used to represent different kinds of things you are
 * trying to print out. Below are some examples of format strings.
 */

#include <stdio.h>

int main() {
    // What if we want to print a number? We use %d to represent an int or digit
    int x = 7;
    printf("The value of x is %d\n", x);

    // What about "strings"? We use %s to represent string that are going to be printed
    printf("This is how to print a string %s\n", "Hello");

    return 0;
}
