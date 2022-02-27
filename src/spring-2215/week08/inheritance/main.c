#include <stdio.h>

#include "num_generator.h"
#include "file_generator.h"
#include "random_generator.h"


int add_gen_results(struct num_generator* first, struct num_generator* second) {

    int first_num = get_next(first);
    int second_num = get_next(second);

    printf("First num: %d, Second num: %d\n", first_num, second_num);
    return first_num + second_num;
}

int main() {

    struct num_generator* first = new_file_gen("input.txt");
    struct num_generator* second = new_random();

    while(has_next(first) && has_next(second)) {
        printf("Sum: %d\n", add_gen_results(first, second));
    }

    free_generator(first);
    free_generator(second);

    return 0;
}
