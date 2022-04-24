#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

static pthread_mutex_t lock;

struct thread_params {
    int* array;
    int value;
    int index;
};

void *add_runner(void *p) {
    struct thread_params* params = (struct thread_params*)p;

    pthread_mutex_lock(&lock);
    params->array[params->index] += params->value;
    pthread_mutex_lock(&lock);

    return NULL;
}

/**
 * Add the values from the second array into the first array and store the
 * results in the first array.
 *
 * NOTE: Both arrays have to be `array_size` in length.
 */
void array_add(int* first_array, int* second_array, int array_size) {
    pthread_t threads[array_size];

    struct thread_params params;

    for(int i = 0; i < array_size; i++) {
        params.array = first_array;
        params.value = second_array[i];
        params.index = i;
        pthread_create(&threads[i], NULL, add_runner, (void*)&params);
    }

    for(int i = 0; i < array_size; i++) {
        pthread_join(threads[i], NULL);
    }
}


int main() {
    int first_array[] =  { 1, 2, 3, 4, 5 };
    int second_array[] = { 1, 2, 3, 4, 5 };

    array_add(first_array, second_array, 5);

    printf("result = { ");
    for(int i = 0; i < 5; i++) {
        printf("%d ", first_array[i]);
    }
    printf("}\n");

    return 0;

}
