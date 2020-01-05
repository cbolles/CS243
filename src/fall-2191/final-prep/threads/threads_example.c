/**
 * file: threads_example.c
 *
 * The following is an example of running multiple threads together.
 *
 * @author Collin Bolles
 */
#include <pthread.h> // Include for POSIX threads
#include <stdio.h>

/**
 * Here is an example of a function which can run as a thread. Notice the return type and the
 * parameter type, this is restricted by the function pointer expected by the pthread_create
 * function.
 */
void *my_thread(void *parameter) {
    int thread_number = (int) parameter;
    printf("Hello from thread %d\n", thread_number);
    pthread_exit(parameter);
}

int main() {
    pthread_t thread_ids[10];
    for(long i = 0; i < 10; i++)
        pthread_create(&thread_ids[i], NULL, my_thread, (void *)i);

    for(int i = 0; i < 10; i++) {
        void *return_value;
        pthread_join(thread_ids[i], &return_value);
        printf("Thread number %d has joined\n", (int) return_value);
    }

    return 0;
}
