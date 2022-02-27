#ifndef _NUM_GENERATOR_H_
#define _NUM_GENERATOR_H_

#include <stdbool.h>

struct num_generator {
    void* priv;

    int (*next)(void*);
    bool (*has_next)(void*);
    void (*free)(void*);
};

/**
 * Get if the number generator has another number to give
 *
 * @param self The generator to run on
 * @return True if the generator has another number
 */
bool has_next(struct num_generator* self);

/**
 * Get the next number, will always return 0 if the generator no longer
 * has any numbers to give
 *
 * @param self The generator to run on
 * @return The next number the generator has or 0
 */
int get_next(struct num_generator* self);

/**
 * Free the generator and its private data
 */
void free_generator(struct num_generator* self);
#endif
