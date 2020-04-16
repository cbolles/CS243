#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

#define NUM_THREADS 5

void *thread_run(void *param) {
    long thread_num = (int)param;

    for(long i = 0; i < thread_num; i++) {
        usleep(100);
        putc('t', stdout);
    }

    printf("\n");
    pthread_exit(NULL);
}

int main() {
    pthread_t thread_ids[NUM_THREADS];
    printf("Hello from main thread\n");

    // Start up all threads
    for(long i = 0; i < NUM_THREADS; i++) 
        pthread_create(&thread_ids[i], NULL, thread_run, (void *)i);

    // Join all threads
    for(int i = 0; i < NUM_THREADS; i++) {
        void *return_value;
        pthread_join(thread_ids[i], &return_value);
    }

    return 0;
}
