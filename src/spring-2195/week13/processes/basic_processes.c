/**
* Processes are created in UNIX by splitting off of one process into another
* process. The example below shows a super basic use of processes.
*
* @author Collin Bolles
*/
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    // Get the process ID for the parent before calling fork
    pid_t parent_id = getpid();
    printf("The initial process (parent) has an id of %d\n", parent_id);

    // Now call fork, once we call fork we will have two processes running (unless error)
    pid_t child_id = fork();

    switch(child_id) {
        // If the child_id == -1, we had a failed attempt to create a process   
        case -1:
            perror("fork");
            // If we have an error, end code execution
            exit(EXIT_FAILURE);
        // The child process gets 0 for the value returned from fork, if child_id == 0, then the process is running 
        case 0:
            printf("Hello from child process!\n");
            sleep(10);
            printf("The child process is now ending\n");
            return EXIT_FAILURE;
            break;
        // Any other value is the id of the child which the parent process is given
        default:
            printf("Hello from parent process!\n");
            printf("Parent is now waiting for the child to end in process %d\n", child_id);
            int status;
            wait(&status);
            printf("The child exited with status %d\n", status);
            break;
    }
    
    // Parent's exit
    return 0;
}

