.RECIPEPREFIX = >
CC = gcc
CC_FLAGS = -Wall -Wextra -pedantic -std=c99

main: main.o file_generator.o random_generator.o num_generator.o
> $(CC) $(CC_FLAGS) -o main main.o file_generator.o random_generator.o num_generator.o

main.o: main.c num_generator.h file_generator.h random_generator.h
> $(CC) $(CC_FLAGS) -c main.c

file_generator.o: file_generator.c num_generator.h
> $(CC) $(CC_FLAGS) -c file_generator.c

random_generator.o: random_generator.c num_generator.h
> $(CC) $(CC_FLAGS) -c random_generator.c

num_generator.o: num_generator.c num_generator.h
> $(CC) $(CC_FLAGS) -c num_generator.c
