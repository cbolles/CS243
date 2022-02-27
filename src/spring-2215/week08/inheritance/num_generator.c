#include <stdlib.h>

#include "num_generator.h"

bool has_next(struct num_generator* self) {
    return self->has_next(self->priv);
}

int get_next(struct num_generator* self) {
    if(self->has_next(self->priv)) {
        return self->next(self->priv);
    }
    return 0;
}

void free_generator(struct num_generator* self) {
    self->free(self->priv);
    free(self);
}
