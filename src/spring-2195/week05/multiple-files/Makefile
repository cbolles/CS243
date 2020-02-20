main: main.o shapes.o
	gcc -Wall -Wextra -pedantic -std=c99 -o main.out main.o shapes.o

main.o: main.c
	gcc -Wall -Wextra -pedantic -std=c99 -c main.c

shapes.o: shapes.c shapes.h
	gcc -Wall -Wextra -pedantic -std=c99 -c shapes.c
