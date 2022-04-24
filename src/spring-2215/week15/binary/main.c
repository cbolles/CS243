#include <stdio.h>


void print_bin(unsigned char c) {
    printf("%d = 0b", c);
    for(int i = 0; i < 8; i++) {
        printf("%d", c >> (8 - i - 1) & 1);
    }
    printf("\n");
}

int main() {

    print_bin(1);
    print_bin(10);
    print_bin(255);

    return 0;
}
