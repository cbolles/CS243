#include <stdio.h>

void foo() () {
    printf("Hello\n");
}

int bar(int x) {
    printf("%d\n", x);
    return x;
}

int compareInt(void *value_one, void *value_two) {
    
}

int compareChar(void *value_one, void *value_two) {

}

void sort(LinkedList list, int (*compareTo)(void *, void *)) {
        
}

int main() {
    void (*z)() = foo;
    sort(my_list, compareChar);
    sort(another_list, compareInt);
    return 0;
}
