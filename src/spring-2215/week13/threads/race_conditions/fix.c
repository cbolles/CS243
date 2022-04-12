#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

long total_balance = 0;

static pthread_mutex_t m_lock;

/**
 * This runner will wait until the total balance is greater then
 * the amount it is trying to remove before applying a subtraction.
 */
void *safe_withdraw(void* param) {
    long amount = (long)param;
    int is_waiting = 1;

    while (is_waiting) {
        usleep(100);
        pthread_mutex_lock(&m_lock);
        if(total_balance >= amount) {
            is_waiting = 0;
        }
        pthread_mutex_unlock(&m_lock);
    }

    pthread_mutex_lock(&m_lock);
    total_balance -= amount;
    pthread_mutex_unlock(&m_lock);

    return NULL;
}

/**
 * This runner will add an amout to the total balance.
 */
void *safe_deposit(void* param) {
    long amount = (long)param;

    pthread_mutex_lock(&m_lock);
    total_balance += amount;
    pthread_mutex_unlock(&m_lock);


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

    pthread_mutex_init(&m_lock, NULL);
    for(int i = 0; i < 100; i++) {
        simulate();
        usleep(100);
    }

    return 0;
}
