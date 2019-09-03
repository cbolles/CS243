/**
 *  file: hello_world.c
 *
 * To compile to executable:
 *      gcc -std=c99 -Wall -Wextra -pedantic -o hello_world hello_world.c
 * 
 * To run:
 *      ./hello_world  
 * 
 * @author: Collin Bolles
*/
#include <stdio.h> // Get me the functions from the standard io library


/**
 * The main method that we will use to run our code. 
 * 
 * This is like the "public static void main" method from Java. Unlike Java, 
 * this function has a return type, int. This is the "exit status" used to say
 * if the program exited correctly, or failed.
 * 
 * Compare this code to "hello_word.py" and "hello_world.java" to see the differences
 * 
 * Note that printf has the "\n" built in, c is very literal, try removing the "\n"
 * compile and re-run the code to see what happens.
 */ 
int main() {
    printf("Hello World\n"); //Print "Hello World" then add a new line
    return 0; // Return 0 to say that the program ran successfully.
}