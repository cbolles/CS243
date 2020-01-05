#include <stdio.h>
#include <string.h>

void reverse(char str[]) {
    size_t str_len = strlen(str);
    for(int i = str_len - 1; i >= 0; i--)
        printf("%c", str[i]);
    printf("\n");
}

int main() {
    reverse("Hello");
    reverse("World");

    return 0;
}
