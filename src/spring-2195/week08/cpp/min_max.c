/**
 * Below is a basic example of using macros. In this example we have two
 * macros. One for min one for max.
 *
 * @author Collin Bolles
 */

#include <stdio.h>

#define MIN(x, y) x > y ? y : x
#define MAX(x, y) x > y ? x : y

int main() {
    int num_1 = 5;
    int num_2 = 10;

    printf("The min is %d\n", MIN(num_1, num_2));
    printf("The max is %d\n", MAX(num_1, num_2));

    return 0;
}
