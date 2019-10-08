/**
 * file: function_pointer.c
 *
 * Function pointers allow use to point to memory in the text section of our memory. We can
 * use this to execute functions.
 *
 * In this example we can start to see how we can create some "object oriented" like
 * functionality.
 *
 * @author Collin Bolles
 */
#include <stdio.h> // print
#include <stdlib.h> // malloc
#include <string.h> // strlen, strcpy

/**
 * A dog structure has a name and an age associated with it, a dog can speak
 */
typedef struct dog_s {
    char *name;
    int age;
    void (*speak)();
} Dog;

void dog_speak() {
    printf("Bark\n");
}

Dog *create_dog(char *name, int age) {
    Dog *new_dog = malloc(sizeof(Dog));

    // Populate the dog's name
    new_dog->name = malloc(strlen(name) + 1);
    strcpy(new_dog->name, name);

    // Populate the dog's age
    new_dog->age = age;

    // Add the ability to speak
    new_dog->speak = dog_speak;

    return new_dog;
}

void free_dog(Dog *dog) {
    free(dog->name);
    free(dog);
}

/**
 * The cat structure has a name and an age associated with it, a cat can speak
 */
typedef struct cat_s {
    char *name;
    int age;
    void (*speak)();
} Cat;

void cat_speak() {
    printf("Meow\n");
}

Cat *create_cat(char *name, int age) {
    Cat *new_cat = malloc(sizeof(Cat));

    // Populate name
    new_cat->name = malloc(strlen(name) + 1);
    strcpy(new_cat->name, name);

    // Populate age
    new_cat->age = age;

    // Add ability to spea
    new_cat->speak = cat_speak;

    return new_cat;
}

void free_cat(Cat *cat) {
    free(cat->name);
    free(cat);
}

int main() {
    Dog *my_dog = create_dog("Archie", 8);
    Cat *my_cat = create_cat("Sam", 11);
    
    my_dog->speak();
    my_cat->speak();

    return 0;
}

