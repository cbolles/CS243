/**
 * file: main.c
 *
 * To compile to an object file:
 *      gcc -std=c99 -Wall -Wextra -pedantic -c main.c
 * 
 * To create an executable:
 *      gcc -std=c99 -Wall -Wextra -pedantic -o main main.o circle.o
 *
 * To run:
 *      ./main
 * 
 * NOTE: You have to make the circle object file before making the executable
 *
 * @author Collin Bolles
 */

#include <stdio.h> // printf
#include "circle.h" // NOTE: We do not include "circle.c" we include the header, gcc links the two together

/**
 * Main method computes the area of a circle with a given radius and prints the output
 */
int main() {

    int radius = 10;
    float area = getArea(radius);

    printf("Area of a circle with radius %d is %f\n", radius, area);
    return 0; // Successful exit;
}
