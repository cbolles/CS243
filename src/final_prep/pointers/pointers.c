#include <stdio.h>

int main() {
    int a = 10;
    int x = 20;
    int *b = &a;
    int **c = &b;
    **c = 20;
    b = &x;
    *c = 30;
    *b = 30;
    return 0;
}
