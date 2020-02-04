/**
 * Strtol is a great utility for converting strings to longs. But in C we are limited in what we can
 * do so we can see that strtol makes use of some cool tricks to make our life as developers easier.
 *
 * @author Collin Bolles
 */

#include <stdio.h>
#include <stdlib.h>

int main() {

    long result

    // Most basic example of strtol
    char example[] = "7";
    result = strtol(example, NULL, 10);
    printf("The first example parses %s into %ld\n", example, result);

    // What about when we have some extra stuff?
    char another[] = "7a";
    char *ptr;
    result = strtol(another, &ptr, 10);
    printf("The second example parses %s into %ld with %s left over\n", another, result, ptr);

    // What about if nothing can be parsed?
    char yet_another[] = "hello";
    result = strtol(yet_another, NULL, 10);
    printf("The third example parses %s into %ld\n", yet_another, result);

    return 0;
}
