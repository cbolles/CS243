#include <stdio.h>

int talk() {
    printf("Hello\n");
    return 0;
}

int main() {
    void (*example)() = talk;
    example();
    return 0;
}
