#include <stdio.h>


int main() {
    int array[3] = { 1, 2, 3 };
    int *data = array;

    for(int i = 0; i < 3; i++) {
        printf("Data stores addres %p which has the value %d\n", (void *)data, *data);
        data++;;
    }

    return 0;
}
