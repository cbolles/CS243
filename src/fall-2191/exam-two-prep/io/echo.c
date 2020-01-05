#include <stdio.h>

#define MAX_LINE 50

int main() {
    char input[MAX_LINE];
    while(fgets(input, MAX_LINE, stdin))
        fputs(input, stdout);
    return 0;
}
