/**
 * file: getchar.c
 *
 * To compile to an executable:
 *      gcc -Wall -Wextra -pedantic -std=c99 -o getchar getchar.c
 * 
 * To execute:
 *      ./getchar
 *
 * Some of the basics of reading characters one at a time. This program takes the input and prints it back out
 *
 * @author Collin Bolles
 */
#include <stdio.h> // printf, getchar

int main() {
    printf("Enter a letter press control-d to exit: ");

    char letter = getchar(); // Pull the next character from the input

    while(letter != EOF) { // While we haven't reached the end of the file
        if(letter != '\n') // If the character is not a new line
            printf("%c ", letter);
        letter = getchar();
    }
    
    printf("\n");

    return 0;
}
    
