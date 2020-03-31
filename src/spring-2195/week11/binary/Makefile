CC = gcc
CFLAGS = -Wall -Wextra -pedantic -std=c99 -ggdb

all: read_people write_people

read_people: read_person.o person.o
	${CC} ${CFLAGS} -o read_person.out read_person.o person.o

write_people: write_person.o person.o
	${CC} ${CFLAGS} -o write_person.out write_person.o person.o

read_person.o: read_person.c
	${CC} ${CFLAGS} -c read_person.c

write_person.o: write_person.c
	${CC} ${CFLAGS} -c write_person.c

person.o: person.c person.h
	${CC} ${CFLAGS} -c person.c
