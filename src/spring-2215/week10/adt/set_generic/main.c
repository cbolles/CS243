#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "set.h"

int cmp_in(void *first, void *second) {
    int first_int = (int)first;
    int second_int = (int)second;

    if(first_int < second_int) {
        return -1;
    }
    else if(first_int == second_int) {
        return 0;
    }
    else {
        return 1;
    }
}

void free_int(void *elem) {
    (void)elem;
}

void print_int(void *elem) {
    printf("%d", (int)elem);
}

void int_set() {
    Set set = new_set(cmp_in, free_int, print_int);

    set_insert(set, (void*)1);
    set_insert(set, (void*)2);
    set_insert(set, (void*)3);
    set_insert(set, (void*)1);

    print_set(set);

    set_remove(set, (void*)2);

    print_set(set);

    free_set(set);
}

struct person {
    char* first_name;
    char* last_name;
    size_t age;
};

struct person *new_person(char *first, char *last, size_t age) {
    struct person *p = malloc(sizeof(struct person));
    p->first_name = malloc(strlen(first) + 1);
    p->last_name = malloc(strlen(last) + 1);

    strcpy(p->first_name, first);
    strcpy(p->last_name, last);
    p->age = age;

    return p;
}

int cmp_person(void *first, void *second) {
    struct person *first_p = (struct person*)first;
    struct person *second_p = (struct person*)second;

    return strcmp(first_p->last_name, second_p->last_name);
}

void print_person(void *elem) {
    struct person *p = (struct person*)elem;

    printf("First Name: %s, Last Name: %s, Age: %lu", p->first_name,
           p->last_name, p->age);
}

void free_person(void *elem) {
    struct person *p = (struct person*)elem;

    free(p->first_name);
    free(p->last_name);
    free(p);
}

void person_set() {
    Set set = new_set(cmp_person, free_person, print_person);

    set_insert(set, new_person("Collin", "Bolles", 22));
    set_insert(set, new_person("Sarah", "Smith", 18));

    print_set(set);
}

int main() {

    person_set();
    return 0;
}

