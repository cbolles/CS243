#ifndef _SET_H_
#define _SET_H_

#include <stdbool.h>
#include <stdlib.h>

#ifndef _SET_IMPL_

typedef struct{ } *Set;

#endif

/**
 * Create a new empty set.
 */
Set new_set();

/**
 * Get the current number of elements stored in the set.
 *
 * @param set The set to get the length of
 * @return The length of the set
 */
size_t length(Set set);

/**
 * Add an element to the set. If the element is already in the set, then
 * nothing occurs.
 *
 * @param set The set to add to
 */
void add(Set set, int element);

/**
 * Removed the given element from the set.
 *
 * @param set The set to remove the element from
 * @param element The element to remove from the set
 */
void set_remove(Set set, int element);

/**
 * Check to see if the set contains the given element.
 *
 * @param set The set to check through
 * @param element The element to search for
 * @return True if the element is found
 */
bool contains(Set set, int element);

/**
 * Free the set.
 *
 * @param set The set to free
 */
void free_set(Set set);

/**
 * Print the contents of the set
 *
 * @param set The set to print out
 */
void print_set(Set set);


#endif
