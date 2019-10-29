CC = gcc
FLAGS = -Wall -Wextra -pedantic -std=c99

main : main.o binary_tree.o
	${CC} -o main main.o binary_tree.o

main.o : main.c binary_tree.h
	${CC} ${FLAGS} -c main.c

binary_tree.o : binary_tree.c binary_tree.h
	${CC} ${FLAGS} -c binary_tree.c
