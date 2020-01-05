#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum Color {
    BROWN,
    GREY,
    GINGER
};

typedef struct cat_s {
    char *name;
    int age;
    enum Color color;
    void (*meow)();
} Cat;

void cat_speak() {
    printf("Meow\n");
}

Cat *make_cat(char *name, int age, enum Color color) {
    Cat *cat = malloc(sizeof(Cat));
    cat->name = malloc(strlen(name) + 1);
    strcpy(cat->name, name);
    cat->age = age;
    cat->color = color;
    cat->meow = cat_speak;
    return cat;
}

void free_cat(Cat *cat) {
    free(cat->name);
    free(cat);
}

int main() {
    Cat *cat = make_cat("Sammy", 10, BROWN);
    printf("The cat says ");
    cat->meow();
    free_cat(cat);
    return 0;
}
