#include <stdio.h>


int main() {
    char user_input[5];
    for(int i = 0; i < 5; i++) {
        printf("Enter character number %d: ", i + 1);
        user_input[i] = getchar();
        getchar(); // We don't want to get the newline
        printf("\n");
    }

    printf("User input: ");
    for(int i = 0; i < 5; i++) {
        printf("%c", user_input[i]);
        if(i < 4) 
            printf(", ");
    }
    printf("\n");

    return 0;
}
