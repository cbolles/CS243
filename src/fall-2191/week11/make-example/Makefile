CC = gcc
CC_FLAGS = -Wall -Wextra -pedantic -std=c99

main: main.o linked_list.o node.o
	$(CC) $(CC_FLAGS) -o main main.o linked_list.o node.o

main.o: main.c linked_list.h
	$(CC) $(CC_FLAGS) -c main.c

linked_list.o: linked_list.c linked_list.h node.h
	$(CC) $(CC_FLAGS) -c linked_list.c

node.o: node.c node.h
	$(CC) $(CC_FLAGS) -c node.c
