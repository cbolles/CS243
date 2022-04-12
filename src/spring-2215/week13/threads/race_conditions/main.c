#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

long total_balance = 0;

/**
 * This runner will wait until the total balance is greater then
 * the amount it is trying to remove before applying a subtraction.
 */
void *safe_withdraw(void* param) {
    long amount = (long)param;

    while (total_balance < amount) {
        usleep(100);
    }

    total_balance -= amount;

    return NULL;
}

/**
 * This runner will add an amout to the total balance.
 */
void *safe_deposit(void* param) {
    long amount = (long)param;

    total_balance += amount;

    return NULL;
}


/**
 * Simulate a series of bank transactions of depositing and withdrawing.
 * The bank wants to make sure a withdraw can only take place if there is
 * a certain amount in the bank
 */
void simulate() {
    pthread_t threads[5];

    // Reset for this run
    total_balance = 0;

    pthread_create(&threads[0], NULL, safe_withdraw, (void*)500);
    pthread_create(&threads[1], NULL, safe_deposit, (void*) 500);
    pthread_create(&threads[2], NULL, safe_withdraw, (void*)1000);
    pthread_create(&threads[3], NULL, safe_deposit, (void*)5);
    pthread_create(&threads[4], NULL, safe_deposit, (void*)1000);

    // Join all
    for(int i = 0; i < 5; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Final deposite: %ld\n", total_balance);
}

int main() {
    for(int i = 0; i < 100; i++) {
        simulate();
        usleep(100);
    }

    return 0;
}
