#include <stdio.h>
    
int main() {
    int a[3][3];
    int **p = &a[0];

    printf("Original %p\n", p);
    (*p)++;
    printf("Final %p\n", p);

    return 0;
}
