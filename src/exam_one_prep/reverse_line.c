/**
 * file: reverse_line.c
 *
 * To compile to an executable:
 *      gcc -Wall -Wextra -pedantic -std=c99 -o reverse_line reverse_line.c
 *
 * To execute:
 *      ./reverse_line
 *
 * This program takes in a single line from stdin from the user and will reverse the line, then print out the result to the stdout using fprintf.
 * 
 * fgets is used to read in a single line from a specific file to a maximum size that you specify.
 *
 * fprintf prints to a specific file
 *
 * @author Collin Bolles
 */

#include <stdio.h> //printf, fgets, fprintf
#include <string.h> //strlen

#define MAX_LINE_SIZE 100 //The biggest the line entered by the user can be

void get_reversed(char original[], char reversed[]) {
    size_t original_length = strlen(original); // Get the length of the original using strlen, note the type is size_t
    for(int i = original_length - 1; i >= 0; i--) {
            reversed[i] = original[original_length - i - 1];
    }
    reversed[original_length] = '\0'; // WE HAVE TO ADD THE NULL TERMINATOR!!
}

int main() {
    fprintf(stdout, "Enter the line to reverse: ");

    // Read in a string from stdin into a character array of a maximum size
    char user_input[MAX_LINE_SIZE];
    fgets(user_input, MAX_LINE_SIZE, stdin);

    // Reverse the character and store the result in a new character array
    char reversed[MAX_LINE_SIZE];
    get_reversed(user_input, reversed);
    fprintf(stdout, "The line reversed is: %s\n", reversed);

    return 0;
}
