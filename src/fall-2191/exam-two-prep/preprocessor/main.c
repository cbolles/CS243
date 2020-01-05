#include <stdio.h>

#define MAX(a,b) a > b ? a : b
#define VALID 0

#define PRINT_MAX(a, b) printf("The biggest number is %d\n", MAX(a, b));
#define PRINT_B printf("The value of b is less than 10\n");
#define RETURN_GOOD return 0;

int main() {
    int a = 50;
    int b = 5;

    PRINT_MAX(a, b)
    #if VALID
        PRINT_B
    #endif
    RETURN_GOOD
}
