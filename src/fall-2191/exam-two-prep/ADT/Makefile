CC = gcc
C_FLAGS = -Wall -Wextra -pedantic -std=c99

main: main.o array.o
	$(CC) $(C_FLAGS) -o main main.o array.o

main.o: main.c array.h
	$(CC) $(C_FLAGS) -c main.c

array.o: array.c array.h
	$(CC) $(C_FLAGS) -c array.c
