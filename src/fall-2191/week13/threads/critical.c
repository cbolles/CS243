#include <pthread.h> // Thread related source
#include <stdio.h>

size_t current_position = 0;
int array[10];


pthread_mutex_t lock;

void *my_thread(void *input) {
    int my_num = (int)input;

    // Lock the critical section
    pthread_mutex_lock(&lock);
    array[current_position++] = my_num;
    pthread_mutex_unlock(&lock);

    return NULL;
}

int main() {
    pthread_t thread_ids[10];

    // Initialize the lock
    pthread_mutex_init(&lock, NULL);

    for(long i = 0; i < 10; i++)
        pthread_create(&thread_ids[i], NULL, my_thread, (void *)i);

    // Join threads
    void *return_result;
    for(int i = 0; i < 10; i++)
        pthread_join(thread_ids[i], &return_result);

    for(int i = 0; i < 10; i++)
        printf("array[%d] = %d\n", i, array[i]);

    return 0;
}
