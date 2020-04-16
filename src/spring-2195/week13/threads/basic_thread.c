#include <pthread.h> // Thread related source
#include <stdio.h> // printf

void *hello(void * param) {
    (void)param; // Quiet warnings that param is not used
    printf("Hello from a thread!\n");
    pthread_exit(NULL); // Don't need to return anything;
}

int main() {
    pthread_t thread_id;
    pthread_create(&thread_id, NULL, hello, NULL);
    
    void *return_value;
    pthread_join(thread_id, &return_value);
    
    return 0;
}
