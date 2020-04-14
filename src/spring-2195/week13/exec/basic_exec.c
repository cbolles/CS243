#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    // Get PID of parent
    pid_t parent_pid = getpid();
    printf("Parent process running with pid %d\n", parent_pid);

    // Fork to make child process
    pid_t child_pid = fork();

    switch(child_pid) {
        // If the child_pid == -1, we had an error with fork
        case -1:
            perror("fork");
            exit(EXIT_FAILURE);

        // If child_pid == 0, then this is the child process running
        case 0:
            printf("Hello from child process!\n");

            // Setup arguments for the exec call
            char *exec_args[3];
            exec_args[0] = "cat";
            exec_args[1] = "basic_exec.c";
            exec_args[2] = NULL;

            // Run exec, execution should be consumed by the exec call
            execvp("cat", exec_args);

            // We only get here if there was an error
            perror("execvp");
            _exit(EXIT_FAILURE);
        
        // If the pid is anything other then -1 or 0, then the parent is here
        default:
            printf("Hello from parent process!\n");
            printf("Waiting for child process %d\n", child_pid);
            int child_return_status;
            wait(&child_return_status);
            printf("Child processes ended with status %d\n", child_return_status);
            break;
    }

    return 0;
}

