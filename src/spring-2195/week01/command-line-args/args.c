/**
 * file: args.c
 *
 * The following is an example of using command line arguments in C. In C arrays are what many
 * see as "pure" arrays. They are a sequence of elements and that is it! No ".size" or ".length".
 * So we need to know how many elements are in the array which is why we have argc.
 *
 * @author Collin Bolles
 */

#include <stdio.h> // printf

int main( int argc, char * argv[] ) {
    for(int i = 0; i < argc; i++) {
        printf("Argument %d: %s\n", i, argv[i]);
    }

    return 0;
}
