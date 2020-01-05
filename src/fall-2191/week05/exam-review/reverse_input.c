#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[]) {
    // Get the first parameter and the size of the user input
    char* user_input  = argv[1];
    size_t user_input_size = strlen(user_input);

    // Create a new string to hold the reversed output
    char reverse[user_input_size + 1];

    // Reverse the string into the new array
    for(size_t i = 0; i < user_input_size; i++)
        reverse[user_input_size - i - 1] = user_input[i];

    // Don't forget to add the null pointer!!
    reverse[user_input_size] = '\0';

    // Print out the original and the reversed
    printf("The original input: %s\n", user_input);
    printf("The reverse: %s\n", reverse);
    
    // Everything good!
    return 0;
}
