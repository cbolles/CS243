#include <string.h>
#include <stdio.h>

int main() {
    char str[] = "hello,there,how,are,you";
    char *token = strtok(str, ",");
    while(token != NULL) {
        printf("%s\n", token);
        token = strtok(NULL, ",");
    }
    printf("%s\n", str);
    return 0;
}
