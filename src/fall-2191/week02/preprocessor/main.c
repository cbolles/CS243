/**
 * file: main.c
 *
 * To compile into an executable:
 *      gcc -Wall -Wextra -pedantic -std=c99 -o main main.c
 * 
 * To execute:
 *      ./main
 *
 * To see the results of preprocessing:
 *      gcc -E main.c
 *
 * The preprocessor does a lot of "cleaning" to your code before compilation takes place. We will spend more time in class going over
 * what it does, but in class we talked already about some of the things it can do.
 *
 * #define is used to create a preprocessor symbol which acts as a "find a replace" in your code, below are some cool examples of using
 * the #define.
 *
 * @author Collin Bolles
 */

#include <stdio.h>

#define PI 3.14159 // Pretty straight forward, create a symbol that represnets PI

#define FIVE_TIMES 5 * // This looks weird, but remember, this is a "find and replace" very literally

#define PRINT_HELLO_WORLD printf("Hello World!\n") // Why not?

int main() {
    printf("Pi is represented as %f\n", PI);
    printf("5 times 4 is %d\n", FIVE_TIMES 4); // NOTE: We don't have a multiplication sign? Why do you think that is?
    PRINT_HELLO_WORLD;
    return 0; // Everything good!
}
