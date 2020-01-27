/**
 * Here is a basic example of IO in which the program prompts the user to enter there name after
 * which the program welcomes them.
 *
 * @author Collin Bolles
 */
#include <stdio.h> // printf, fgets

#define MAX_NAME_LENGTH 20

int main() {

    // Name prompt
    printf("Please enter your name: ");
    
    // Create a string that can hold the person's name
    char name[MAX_NAME_LENGTH];

    // Use fgets to read in the name
    fgets(name, MAX_NAME_LENGTH, stdin);

    printf("Hello %s", name);

    // Why do I not include a new line character in either of the print statements?
    return 0;
}
