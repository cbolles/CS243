#include "random_generator.h"

/**
 * Generate a new random number. Note here, we don't need any additional
 * data
 */
static int random_next(void* priv) {
    return rand();
}

/**
 * Can always produce a new numbers, so always returns true/
 */
static bool random_has_next(void* priv) {
    return true;
}

/**
 * Freeing does nothing since the "private" data isn't used
 */
static void random_free(void* priv) { }

struct num_generator* new_random() {
    srand(time(NULL));

    // Allocate space for the generator
    struct num_generator* gen = (struct num_generator*)
        malloc(sizeof(struct num_generator));

    gen->priv = NULL;  // Don't need any private data
    gen->next = random_next;
    gen->has_next = random_has_next;
    gen->free = random_free;

    return gen;
}
