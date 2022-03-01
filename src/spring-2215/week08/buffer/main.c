#include <stdio.h>

int main() {

    printf("%s", "hello");
    int a = *(int*)NULL;
    printf("%s", "world");

    return 0;
}
