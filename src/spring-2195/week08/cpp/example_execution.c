/**
 * The C-preprocess as we have seen has a little bit more power then just a
 * basic find and replace. Based on the code below, determine what the
 * output is going to be.
 *
 * @author Collin Bolles
 */

#include <stdio.h>

#define A
#define B
#define C

int main() {
    #ifdef A
        printf("Hello\n");
        #ifndef B
            printf("World\n");
        #endif
        printf("Another\n");
        #ifdef C
            printf("Example\n");
        #endif
    #endif
    return 0;
}
