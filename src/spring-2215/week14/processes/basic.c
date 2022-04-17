#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    printf("Parent process is starting with PID: %d\n", getpid());

    pid_t id = fork();

    switch(id) {
        case -1:
            printf("Fork failed :(\n");
            exit(1);
        case 0:
            printf("Hello from child, press enter to stop the child\n");
            getc(stdin);
            _exit(0);
        default:
            printf("Hello from parent\n");
    }

    printf("Parent now waiting for child to complete\n");

    int status;
    wait(&status);

    printf("Child process terminated\n");

    return 0;

}
