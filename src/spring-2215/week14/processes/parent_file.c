#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    FILE* my_file = fopen("test.txt", "w");

    fprintf(my_file, "Parent process is starting with PID: %d\n", getpid());

    // NOTE: comment me out for something interesting
    // fflush(my_file);

    int my_number = 0;

    // Create the child process
    pid_t id = fork();
    switch(id) {
        case -1:
            fprintf(my_file, "Fork failed :(\n");
            exit(1);
        case 0:
            printf("Hello from child, press enter to stop the child\n");
            getc(stdin);
            my_number++;
            fprintf(my_file, "oops\n");
            fflush(my_file);
            printf("The number is %d\n", my_number);
            _exit(0);
        default:
            fprintf(my_file, "Hello from parent\n");
    }

    fprintf(my_file, "Parent now waiting for child to complete\n");

    int status;
    wait(&status);

    fprintf(my_file, "Child process terminated\n");

    fprintf(my_file, "The value of my_number: %d\n", my_number);

    fclose(my_file);

    return 0;

}
