#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    pid_t fork_pid = fork();
 
    // Child process
    if(fork_pid == 0) {
        char *process_params[2];
        process_params[0] = "pwd";
        process_params[1] = NULL;
        execvp("pwd", process_params);
    }
    // Parent
    else {
        int status;
        wait(&status);
    }
    return 0;
}
