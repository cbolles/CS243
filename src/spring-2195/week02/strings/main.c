/**
 *
 * In C we do not have strings like we are use to in Python or Java. They are much more primative
 * and have less features then we may be use to.
 *
 * @author Collin Bolles
 */

#include <stdio.h> // printf
#include <string.h> // strcpy

#define MAX_LENGTH 10

int main() {

    // Create an array of chars to hold my string
    char str[MAX_LENGTH];

    strcpy(str, "Hello"); // Copy hello into str, note we have a limited size

    printf("The value of str is %s\n", str);

    return 0;
}
