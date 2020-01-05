/**
 *
 * file: vowel_check.c
 *
 * To compile to an executable:
 *      gcc -Wall -Wextra -pedantic -std=c99 -o vowel_check vowel_check.c
 *
 * To execute:
 *      ./vowel_check
 * 
 * This example takes in a single character from the user and checks to see if the input is a vowel. If the input is a vowel then the program
 * tells you that it is.
 *
 * In here we use constants, arrays, and control structures
 *
 * @author Collin Bolles
 */

#include <stdio.h> //printf, getchar

const char VOWELS[] = { 'A', 'E', 'I', 'O', 'U', 'a', 'e', 'i', 'o', 'u' };
const int NUM_VOWELS = 10;

/**
 * Takes in a character and checks to see if the character is a vowel.
 *
 * NOTE: C by default doesn't have a concept of bool, instead 0 is treated as false and everything else is true
 *
 * @param letter The letter to check if it is a vowel
 * @return 1 if the character is a vowel, 0 otherwise
 */
int is_vowel(char letter) {
    for(int i = 0; i < NUM_VOWELS; i++) { // Loop through all vowles
        if(letter == VOWELS[i])
            return 1;
    }
    return 0;
}


int main() {
    printf("Enter a letter: ");
    char letter = getchar();
    
    if(is_vowel(letter))
        printf("Yay that is a vowel\n");
    else
        printf("Oh no that is not a vowel\n");

    return 0; // Everything good
}
