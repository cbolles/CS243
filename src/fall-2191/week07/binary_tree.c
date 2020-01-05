/**
 * file: binary_tree.c
 *
 * Binary trees are very helpful structures that can be used to represent a lot of different
 * data. In this example we create a pretty simple example of how to represent one in C and how
 * to interact with it.
 *
 * @author Collin Bolles
 */
#include <stdio.h> // printf
#include <stdlib.h> // malloc, free

/**
 * A node in a binary tree has a value associated with it in this case an in, a left node, and a
 * right node. Each of the other nodes can be null
 */
struct tree_node_s {
    int value;
    struct tree_node_s *left_node;
    struct tree_node_s *right_node;
};

typedef struct tree_node_s Node;

/**
 * Creating a node will allocate space for the node to exist, the value and the subnodes
 * will be given.
 * @param value The value that the created node will have
 * @param left_node The left subnode, can be null
 * @param right_node The right subnode, can be null
 */
Node *create_node(int value, Node *left_node, Node *right_node) {
    Node *node = malloc(sizeof(Node));
    
    node->value = value;
    node->left_node = left_node;
    node->right_node = right_node;

    return node;
}

/**
 * Freeing a tree of nodes. Freeing the node involves first freeing the subnodes before freeing
 * the main node itself.
 * @param node The node to free
 */
void free_tree(Node *node) {
    if(node->left_node != NULL)
        free_tree(node->left_node);
    if(node->right_node != NULL)
        free_tree(node->right_node);
    free(node);
}

int main() {
    // Create the left sub node
    Node *left_node = create_node(1, NULL, NULL);

    // Create the right sub node
    Node *right_node = create_node(9, NULL, NULL);

    // Create the main node
    Node *main_node = create_node(5, left_node, right_node);

    // Free the tree
    free_tree(main_node);

    return 0;
}
