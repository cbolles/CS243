/**
 * With function pointers we now see that we can have a pointer to anywhere in our memory segments.
 * Function pointers are pointers that point into the text segment. They work very simialar to
 * function variables in python.
 *
 * @author Collin Bolles
 */
#include <stdio.h>

void foo() {
    printf("Hello World\n");
}

int bar(int param) {
    printf("%d\n", param);
    return 0;
}

int main() {

    // Basic form of a function pointer
    // <return type>(*<variable name>)(<parameter types>)
    void (*foo_ptr)() = foo;
    foo_ptr();

    int (*bar_ptr)(int) = bar;
    bar_ptr(10);
}
