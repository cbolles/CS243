/**
 * file: circle.c
 *
 * To compile to an object file:
 *      gcc -std=c99 -Wall -Wextra -pedantic -c circle.c
 * 
 * NOTE: No main method, thus you as the user of the code does not directly execute this file
 *
 * Has the implmentation of the getArea function for a circle. 
 *
 * @author Collin Bolles
 */

#include "circle.h" // NOTE: We need to include the header so we have the function header and so we can use PI

/**
 * Get the area of a circle with a given radius
 *
 * @param radius The radius of a circle
 * @return The area of a cirlce
 */
float getArea(int radius) {
    return PI * radius * radius;
}
