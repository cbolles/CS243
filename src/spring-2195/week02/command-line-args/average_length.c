/**
 *
 * Basic example of strings and command line arguments in C. The program takes in a bunch of
 * command line arguments and gets the average length of each argument not including the name
 * of the program.
 *
 * @author Collin Bolles
 */

#include <stdio.h> // printf
#include <string.h> // strlen

int main(int argc, char *argv[]) {
    if(argc < 2) {
        printf("Please pass in at least one command line argument\n");
        return 0;
    }

    int total_length = 0;
    for(int i = 1; i < argc; i++) {
        total_length += strlen(argv[i]);
    }

    int average_length = total_length / (argc - 1);

    printf("The average length is %d\n", average_length);

    return 0;
}
