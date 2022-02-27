#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#include "num_generator.h"
#include "file_generator.h"

struct file_gen_priv {
    FILE *file;
    int next_read;
    bool at_end;
};

static int file_next(void* priv) {
    struct file_gen_priv* self = (struct file_gen_priv*)priv;

    if(self->at_end) {
        return 0;
    }

    int result = self->next_read;

    char buff[50];
    if(fgets(buff, 50, self->file) == NULL) {
        self->at_end = true;
        self->next_read = 0;
    } else {
        self->next_read = strtol(buff, NULL, 10);
    }

    return result;
}

static bool file_has_next(void* priv) {
    struct file_gen_priv* self = (struct file_gen_priv*)priv;

    return !self->at_end;
}

static void file_free(void* priv) {
    struct file_gen_priv* self = (struct file_gen_priv*)priv;

    fclose(self->file);
    free(self);
}

struct num_generator* new_file_gen(char* filename) {
    FILE* file = fopen(filename, "r");

    struct file_gen_priv* self = (struct file_gen_priv*)
        malloc(sizeof(struct file_gen_priv));

    self->file = file;

    // Read in the first value and cache
    char buff[50];
    if(fgets(buff, 50, self->file) == NULL) {
        self->at_end = true;
        self->next_read = 0;
    } else {
        self->at_end = false;
        self->next_read = strtol(buff, NULL, 10);
    }

    struct num_generator* gen = (struct num_generator*)
        malloc(sizeof(struct num_generator));

    gen->priv = self;
    gen->next = file_next;
    gen->has_next = file_has_next;
    gen->free = file_free;

    return gen;
}
