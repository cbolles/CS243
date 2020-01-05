#include <stdio.h>
#include "array.h"

int main() {
    Array *my_array = create_array(5);
    set_element(my_array, 0, 7);
    printf("The element at index 0 is \n", get_element(my_array, 0));
    return 0;
}
