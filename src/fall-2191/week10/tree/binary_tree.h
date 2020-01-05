/**
 * file: binary_tree.h
 *
 * Abstract Data Types refer to data structures in which their implementation is hidden. A
 * "user" of the code (someone including the header file) won't know how the data structure 
 * is built or operates, but knows how to use it.
 *
 * For example, in Java you would import and use the ArrayList, but you never had to know how an
 * ArrayList works.
 *
 * In C, it is harder to create Abstract Data Types since Java makes use of OOP in order to hide
 * the implementation of the data type. With C, we make use of header files to seperate how
 * to use the data type with how the data type is implemented.
 *
 * Here we have a Binary Tree ADT, this header file contains HOW to use the Binary Tree, but not
 * how the binary tree is implemented.
 *
 * @author Collin Bolles
 */

#ifndef BINARY_TREE_H
#define BINARY_TREE_H
// The typedef creates a way to use a binary tree without having to know what the struct looks like
typedef struct binary_tree_s BinaryTree;

/**
 * Used to create a binary tree that stores a value, and has a right and left tree attached to
 * it.
 * @param value The value that is being stored in the tree
 * @param left The left tree, can be NULL
 * @param right The right tree, can be NULL
 * @param print Function pointer that has the ability to print the value of the binary tree
 */
BinaryTree *create_tree(void *value, BinaryTree *left, BinaryTree *right, void(*print)(void *));

/**
 * Prints out the in order representation of the values in the binary tree.
 * @param tree The tree to print
 */
void print_tree(BinaryTree *tree);

/**
 * Frees the memory of the binary tree, not that the value contained in the nodes of the tree will
 * not be freed.
 * @param tree The tree to free
 */
void destroy_tree(BinaryTree *tree);
#endif
