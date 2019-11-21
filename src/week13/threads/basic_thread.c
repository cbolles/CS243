/**
 * file: basic_thread.c
 *
 * This file contains a basic example of using threads, a single thread is spawned, the thread
 * runs a basic calculation, the main thread waits, then everything finishes.
 *
 * @author Collin Bolles
 */

#include<stdio.h>
#include<stdlib.h> // malloc, free
#include<pthread.h> // thread stuff

/**
 * Structure for math operations between two integers, can handle addition, subtraction, 
 * multiplication, and division.
 */
struct math_opt {
    int num_one;
    int num_two;
    char opt;
};

typedef struct math_opt MathOpt;

/**
 * Basic math computes a calculation based on a structure passed in. Add functions that will be
 * run as a thread must return a void pointer and takes a void pointer.
 * @param opt_v A math_opt struct pointer as a void pointer
 * @return A pointer to the resulting number, needs to be freed!
 */
void *basic_math(void *opt_v) {
    MathOpt *opt = (MathOpt *)opt_v; // Cast my opt_v to a MathOpt pointers
    int *result = malloc(sizeof(int)); // Create result in the heap
    
    int num = 0;

    switch(opt->opt) {
        case '+':
            num = opt->num_one + opt->num_two;
            break;
        case '-':
            num = opt->num_one - opt->num_two;
            break;
        case '*':
            num = opt->num_one * opt->num_two;
            break;
        case '/':
            num = opt->num_one / opt->num_two;
            break;
        default:
            break; // Should have error here
    }

    *result = num;
    pthread_exit((void *)result);
}

int main(void) {
    MathOpt my_opt = {7, 7, '+'};

    // Create an id to keep track of the thread
    pthread_t thread_id;

    pthread_create(&thread_id, NULL, basic_math, (void *)&my_opt);

    void *return_value;

    pthread_join(thread_id, &return_value);

    int *result = (int *) return_value;
    printf("%d %c %d is %d\n", my_opt.num_one, my_opt.opt, my_opt.num_two, *result);

    free(result);

    return 0;
}

    


