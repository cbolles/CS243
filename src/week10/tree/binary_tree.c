/**
 * file: binary_tree.c
 *
 * The how to use portion of an ADT is contained in the header file. The implementation is
 * contained in the c file. Here is where the functionality for the binary tree and the structure
 * itself is defined.
 *
 * @author Collin Bolles
 */

#include <stdlib.h> // malloc
#include <assert.h>

/**
 * The implementation of the binary tree, a structure that stores the value and the right and left
 * trees.
 */
struct binary_tree_s {
    void *value; // Can point to anything
    struct binary_tree_s *left;
    struct binary_tree_s *right;
    void (*print)(void *); // Function pointer for printing the contents of the tree
};

#include "binary_tree.h"

/**
 * Creates the binary tree filling in the values of the structure
 */
BinaryTree *create_tree(void *value, BinaryTree *left, BinaryTree *right, void (*print)(void *)) {
    BinaryTree *tree = malloc(sizeof(BinaryTree));
    tree->value = value;
    tree->left = left;
    tree->right = right;
    tree->print = print;
    return tree;
}

/**
 * An in order print functionality that will print out what is stored in the binary
 * tree, uses the function pointer stored in the binary tree
 */
void print_tree(BinaryTree *tree) {
    assert(tree); // Cannot operate on NULL tree
    if(tree->left)
        print_tree(tree->left);
    tree->print(tree->value);
    if (tree->right)
        print_tree(tree->right);
}


/**
 * Destroy the tree freeing up memory
 */
void destroy_tree(BinaryTree *tree) {
    assert(tree); // Cannot operate on NULL tree
    if(tree->left)
        destroy_tree(tree->left);
    if(tree->right)
        destroy_tree(tree->right);
    free(tree);
}
