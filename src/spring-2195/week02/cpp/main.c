/**
 * 
 * The C-Preprocessor is a fancy "find and replace" program much like what you may be use to in
 * Word or any other text editor. You can use them to include files, create "constants", and make
 * macros. For now we will look at including files and making "constants".
 *
 * If you want to see what the C-Preprocessor really does, you can run the command
 * gcc -E <filename>
 * in order to run only the C-Preprocessor on a file.
 *
 * @author Collin Bolles
 */

#include <stdio.h> // printf

#define HELLO_WORLD "hello world\n"
#define CONST 8

// NOTE: We can really use the CPP to replace anything we want
#define PRINT printf("Hey this is kinda weird\n");

int main() {
    printf(HELLO_WORLD);
    
    int x = CONST;

    printf("The value of x is %d\n", x);

    PRINT
    
    return 0;
}
