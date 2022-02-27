#include <stdio.h>

int add(int a, int b) {
    return a + b;
}

int sub(int a, int b) {
    return a - b;
}

float add_f(float a, float b) {
    return a + b;
}

float some() {
    static float a = 5;

    return a;
}

int main(int argc, char **argv) {

    int (*my_fun)(int, int) = some;

    printf("2 + 3 = %d\n", my_fun(2, 3));

    return 0;

}
