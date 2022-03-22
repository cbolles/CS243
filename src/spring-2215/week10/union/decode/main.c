#include <stdio.h>
#include <string.h>

union decoder {
    int input[10];
    char output[40];
};

void print_union(union decoder* uni) {
    printf("The integer values are: ");
    for(int i = 0; i < 10; i++) {
        printf("%d ", uni->input[i]);
    }
    printf("\nThe character values are: ");
    printf("%s\n", uni->output);
}

void fill_input(union decoder* uni, int input[], size_t num_input) {
    for(size_t i = 0; i < num_input; i++) {
        uni->input[i] = input[i];
    }
}

int main() {


    union decoder uni;
    int input[] = {1819043144, 1867980911, 6581362, 0, 0};
    fill_input(&uni, input, 5);

    print_union(&uni);

    return 0;
}
