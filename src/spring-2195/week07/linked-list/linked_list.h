/**
 * Linked list are realivly easy to implement in C now we know about pointer and dynamic memory
 * allocation. Here is a basic implementation of a linked list that can store int values.
 *
 * @author Collin Bolles
 */
#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdlib.h>


// Create the node structure that linked lists use
struct linked_node {
    int value;
    struct linked_node* next;
};

typedef struct linked_node LinkedNode_s;
typedef LinkedNode_s * LinkedNode_t;

// Create the list itself
struct linked_list {
    LinkedNode_t head;
    size_t size;
};

typedef struct linked_list LinkedList_s;
typedef LinkedList_s * LinkedList_t;

/**
 * Create a new linked list, a new linked list is an empty linked list
 *
 * @return A new empty linked list
 */
LinkedList_t new_linked_list();

/**
 * Function to add a value to the linked list. Will be added to the end of the list.
 *
 * @parma list The list to add the value to
 * @param value The value to add to the linked list
 */
void add(LinkedList_t list, int value);

/**
 * Used to get the value at a specific location. Return -1 if index out of bounds
 *
 * @param list The list to get the value from
 * @param index The index to get the value from
 */
int get(LinkedList_t list, size_t index);

/**
 * Used to free a linked list. After freeing all elements will be removed from dynamic memory.
 *
 * @param list The list to free
 */
void free_list(LinkedList_t list);

/**
 * Get the number of elements in the list
 *
 * @param list The list to get the size of
 */
size_t list_size(LinkedList_t list);
#endif
