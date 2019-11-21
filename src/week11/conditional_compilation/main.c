/**
 * file: main.c
 *
 * The preprocessor is capable of handle basic if statements which we have already seen with include
 * guards. Below is a more complex example that involves the C preprocessor. Try running the file
 * throught the preprocessor using gcc -E to see how the output file looks.
 *
 * @author Collin Bolles
 */

#include <stdio.h> // printf

#define SHOULD_HELLO 1

int main() {
    #if SHOULD_HELLO
    printf("Hello\n");
    #else
    printf("Goodbye\n");
    #endif

    return 0;
}
