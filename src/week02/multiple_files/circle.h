/**
 * file: circle.h
 *
 * NOTE: You do not compile h files like you do c files, so there is no instructions to compile
 *
 * You can think of header files like interfaces in Java, they include many function declarations, but can include
 * things such as #define
 *
 * @author Collin Bolles
 */

#ifndef CIRCLE_H // This will be explained later, basically don't want to have multiple instances of the header file
#define CIRCLE_H

/**
 * Create a preprocess symbol to represent PI, every instance of PI found in your source code except in comments and
 * string literals. Programming version of "find and replace" in Word
 */
#define PI 3.14159

/**
 * Create a function header to calculate the area of a circle, note the semi-colon at the end and no implementation.
 *
 * @param radius The radius of a circle to calculate the area of
 * @return The area of a circle as a float
 */
float getArea(int radius);
#endif
