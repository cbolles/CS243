#ifndef _FILE_GENERATOR_H_
#define _FILE_GENERATOR_H_

/**
 * Get a new generator that reads in numbers from a file line-by-line
 */
struct num_generator* new_file_gen(char* filename);

#endif
