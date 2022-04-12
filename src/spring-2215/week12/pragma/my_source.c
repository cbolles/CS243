#include <stdio.h>

#include "my_header.h"
#include "my_header.h"

#pragma message("Compilation is fun")

int main () {

    printf("The value of PI is %f\n", PI);

    #pragma unroll
    for(int i = 0; i < 3; i++) {
        printf("i %d\n", i);
    }

    return 0;
}
