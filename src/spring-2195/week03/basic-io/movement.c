/**
 * This is an example how you can use character IO to make basic movement in a text based game.
 *
 * @author Collin Bolles
 */

#include <stdio.h> // printf, getc

int main() {
    printf("Welcome to my game! Press ctrl-d to quit\n");

    int is_running = 1;
    char user_input = 'w';

    while(is_running) {
        if(user_input != '\n')
            printf("What direction do you want to go in?: ");

        user_input = getchar();

        switch(user_input) {
            case 'w':
                printf("Moving up\n");
                break;
            case 'a':
                printf("Moving left\n");
                break;
            case 's':
                printf("Moving down\n");
                break;
            case 'd':
                printf("Moving right\n");
                break;
            case EOF:
                is_running = 0;
                break;
            case '\n':
                break;
            default:
                printf("I am sorry, that is not a valid direction\n");
                break;
        }
    }

    printf("\nThank you for playing!\n");

    // What does EOF stand for?
    // Why do I have a case for the newline character?
    return 0;
}
