#include <stdio.h>

int reverse_binary(int num) {
    int result = 0;
    int num_bits = sizeof(num) * 8;
    for(int i = 0; i < num_bits; i++) {
        int bit = (num >> i) & 1;
        result |= bit << (num_bits - i - 1);
    }
    return result;
}

void print_bin(int num) {
    int num_bits = sizeof(num) * 8;
    for(int i = 0; i < num_bits; i++) {
        if(num >> i & 1)
            printf("1");
        else
            printf("0");
    }
}

void print_result(int num) {
    int reverse = reverse_binary(num);
    printf("The original:\t");
    print_bin(num);
    printf("\nThe reverse:\t");
    print_bin(reverse);
    printf("\n");
}

int main() {
    print_result(256);
    print_result(11);
    return 0;
}
