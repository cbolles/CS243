/**
 * Sets are very useful structures for holding non-repeating elements. In Computer Science they 
 * are used very heavily. Below is the header for interacting with a set written generically so
 * that the implementation can change.
 *
 * @author Collin Bolles
 */
#ifndef SET_H
#define SET_H

#include <stdbool.h>

typedef struct set_s *Set;

/**
 * Creates a new empty set with no contents. The set will compare elements using the provided
 * compare function and free elements using the given free function.
 * @param cmp Function used to compare two values
 * @param free_element  Function used to free an element in the set, used when freeing whole set
 *                      or removing elements from the set
 * @return Empty set
 */
Set make_set(int (*cmp)(void*, void*), void (*free_element)(void *));

/**
 * Get the number of elements in the given set.
 * @param set The set to get the size of
 * @return The number of elements in the set
 */
size_t length(Set set);

/**
 * Add element to the set. If the element is already in the set, then the set will not be changed.
 * @param set The set to add to
 * @param element The element to add to the set
 */
void add(Set set, void *element);

/**
 * Removes the given value from the set. If the value is not in the set, the set is not changed.
 * @param set The set to remove the element from
 * @param element The element to remove from the set
 */
void remove(Set set, void *element);

/**
 * Checks if the set contains the given value.
 * @param set The set to check the contents of
 * @param element The element to check for
 * @return True if the element is contained in the set, false otherwise
 */
bool contains(Set set, void *element);

/**
 * Checks if the given set is a subset of the other set
 * @param subset Set to check if it is a subset
 * @param superset Set to check if is it the superset
 * @return True if subset is actually the subset of superset
 */
bool is_subset(Set subset, Set superset);

/**
 * Frees the set as well as the contained elements. Makes use of the free function original passed
 * into the set.
 */
void free_set(Set set);
#endif
