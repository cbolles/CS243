#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

#define NUM_HELLO 5
#define NUM_THREADS 10

void *runner(void* param) {
    unsigned long thread_num = (unsigned long)param;

    for(int i = 0; i < NUM_HELLO; i++) {
        printf("Hello from thread %lu: #%d\n", thread_num, i);
    }

    return NULL;
}


int main() {
    pthread_t thread_ids[NUM_THREADS];

    // Start all of the threads
    for(unsigned long thread_num = 0; thread_num < NUM_THREADS; thread_num++) {
        pthread_create(&thread_ids[thread_num], NULL, runner, (void*)thread_num);
    }

    // Join the threads back together
    for(unsigned long thread_num = 0; thread_num < NUM_THREADS; thread_num++) {
        pthread_join(thread_ids[thread_num], NULL);
        printf("Thread %lu joined\n", thread_num);
    }

    return 0;
}
