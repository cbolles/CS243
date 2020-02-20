FLAGS = -Wall -Wextra -pedantic -std=c99

main: main.o linked_list.o
	gcc $(FLAGS) -o main.out main.o linked_list.o

main.o: main.c linked_list.h
	gcc $(FLAGS) -c main.c

linked_list.o: linked_list.h linked_list.c
	gcc $(FLAGS) -c linked_list.c
