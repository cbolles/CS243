/**
 * file: processes.c
 *
 * The following is an exmple of using processes in C. Fork is uses to make a child processes
 * and execvp to run cat.
 */
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    printf("Parent process starting..\n");

    pid_t my_process_id;
    my_process_id = fork(); // Fork creating process
       
    // Child
    if(my_process_id == 0) {
        printf("The child is about to execute a command\n");
        fflush(stdout);
        char *argv[3];
        argv[0] = "cat"; // Command
        argv[1] = "processes.c"; // First parameter
        argv[2] = NULL;
        execvp("cat", argv);
    }
    // Parent
    else {
        printf("Parent is waiting child to complete\n");
        fflush(stdout);
        int status;
        wait(&status);
    }
    return 0;
}
