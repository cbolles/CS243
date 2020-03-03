/**
 * The C Preprocess can be used for conditional compilation. See if you can
 * tell what errors will be generated.
 *
 * @author Collin Bolles
 */

#include <stdio.h>

#define HELLO

int main() {
    #ifdef HELLO
    printf("Hey\n");
    #else
    int x + 1;
    #endif
    return 0;
}
