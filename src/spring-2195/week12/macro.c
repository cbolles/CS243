#include <stdio.h>

#define ADD(x, y) (x + y)

// int x = 7;
// int y = x << 1;
int add(int a, int b) {
    return a + b;
}

int main() {

    int a = 5;
    int b = 6;
    int c = ADD(a, b);
    
    int d = ADD(a, b) * 2;
    int e = add(a, b) * 2;
    return 0;
}
