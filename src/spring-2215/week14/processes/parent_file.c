#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    FILE* my_file = fopen("test.txt", "w");

    fprintf(my_file, "Parent process is starting with PID: %d\n", getpid());

    // NOTE: comment me out for something interesting
    fflush(my_file);

    pid_t id = fork();

    switch(id) {
        case -1:
            fprintf(my_file, "Fork failed :(\n");
            exit(1);
        case 0:
            printf("Hello from child, press enter to stop the child\n");
            getc(stdin);
            fclose(my_file);
            exit(0);
        default:
            fprintf(my_file, "Hello from parent\n");
    }

    fprintf(my_file, "Parent now waiting for child to complete\n");

    int status;
    wait(&status);

    fprintf(my_file, "Child process terminated\n");

    fclose(my_file);

    return 0;

}
