#ifndef _RANDOM_GENERATOR_H_
#define _RANDOM_GENERATOR_H_

#include <stdlib.h>
#include <time.h>
#include <stdlib.h>


#include "num_generator.h"


/**
 * Get a new generator that is able to produce random numbers
 */
struct num_generator* new_random();

#endif
