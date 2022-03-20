.RECIPEPREFIX=|

CC=gcc
CFLAGS=-Wall -Wextra -pedantic -std=c99

main: main.o set.o
| $(CC) $(CFLAGS) -o main main.o set.o

main.o: main.c set.h
| $(CC) $(CFLAGS) -c main.c

set.o: set.c set.h
| $(CC) $(CFLAGS) -c set.c
