/**
 * file: secret_code.c
 *
 * To compile to an executable:
 *      gcc -Wall -Wextra -pedantic -std=c99 -o secret_code secret_code.c
 * 
 * To execute:
 *      ./secret_code
 *
 * This program shows off the C preprocessor in more depth including how it can be difficult sometimes to understand the flow. Hidden inside of this program
 * is a secret message, convert the code into C and see what will be outputted by the program!
 *
 * @author Collin Bolles
 */
#define STANDARD_IO <stdio.h>

#include STANDARD_IO

#define MESSAGE_SIZE 21

#define O_LOCATIONS  { 1, 2, 10 }
#define O_LOOP for(int i = 0; i < 3; i++) {
#define O_LOOP_END }

#define SECOND_WORD {'k', 'c', 'u', 'l'}
#define SECOND_WORD_LOOP for(int i = 5; i < 9; i++) {
#define SECOND_WORD_LOOP_END }

#define LAST_CHARS {'e', 'x', 'a', 'm', ' ', '1', '!'}

int main() {
    char message[MESSAGE_SIZE];
    int o_locations[] = O_LOCATIONS;

    for(int i = 0; i < MESSAGE_SIZE; i++)
        message[i] =  ' ';
    message[0] = 'G';    
    O_LOOP
        message[o_locations[i]] = 'o';
    O_LOOP_END
    message[3] = 'd';
    message[4] =  ' ';

    char second_word[] = SECOND_WORD;
    SECOND_WORD_LOOP
        message[i] = second_word[8 - i];
    SECOND_WORD_LOOP_END
  
    char last_chars[] = LAST_CHARS;
    for(int i = 13; i < MESSAGE_SIZE - 1; i++)
        message[i] = last_chars[i - 13];

    message[11] = 'n'; 
    message[MESSAGE_SIZE - 1] = '\0';
    printf("%s\n", message);
        
    return 0;
}
