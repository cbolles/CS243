#include "linked_list.h"

/**
 * Used to get the last node in the list. If the list is empty, null is returned.
 *
 * @param list The list to get the last element of
 * @return The last node, null if empty list
 */
static LinkedNode_t get_tail(LinkedList_t list) {
    if(list->head == NULL)
        return NULL;
    
    LinkedNode_t previous_node = list->head;
    LinkedNode_t current_node = previous_node->next;
    
    while(current_node != NULL) {
        previous_node = current_node;
        current_node = previous_node->next;
    }
    return previous_node;
}

LinkedList_t new_linked_list() {
    LinkedList_t new_list = malloc(sizeof(LinkedList_s));
    new_list->head = NULL;
    new_list->size = 0;
    return new_list;
}

void add(LinkedList_t list, int value) {
    // Make new node
    LinkedNode_t node = malloc(sizeof(LinkedNode_s));
    node->next = NULL;
    node->value = value;
    LinkedNode_t tail = get_tail(list);

    // Check if empty
    if(tail == NULL) {
        list->head = node;
        list->size = 1;
    }
    else {
        tail->next = node;
        list->size++;
    }
}

int get(LinkedList_t list, size_t index) {
    if(index >= list->size)
        return -1;

    LinkedNode_t node = list->head;
    while(index > 0) {
        node = node->next;
        index--;
    }
    return node->value;
}


void free_list(LinkedList_t list) {
    // Free each node
    LinkedNode_t node = list->head;
    while(node != NULL) {
        LinkedNode_t next_node = node->next;
        free(node);
        node = next_node;
    }
    // Free the list itself
    free(list);
}

size_t list_size(LinkedList_t list) {
    return list->size;
}
