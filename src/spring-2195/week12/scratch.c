#include <stdio.h>

int *ex() {
    static int count = 0;
    count++;
    return &count;
}


void copy_str(char *str) {
    static char my_str[20];
    strcpy(my_str, str);
    return my_str;
}

int main() {
    
    int *count_ptr = ex();
    ex();
    printf("%d\n", *count_ptr);
    return 0;
}
