#include <stdio.h>
#include <string.h>

#define ADD "ADD\n"
#define SUB "SUB\n"
#define MULT "MULT\n"
#define DIV "DIV\n"

#define MAX_USER_IN 50

int main() {
    char user_in[MAX_USER_IN];
    int print_prompt = 1;
    while(!feof(stdin)) {
        if(print_prompt)
            printf("What operations do you want to run?: ");
        fgets(user_in, MAX_USER_IN, stdin);
        
        print_prompt = 1;
        if(strcmp(user_in, ADD) == 0) {
            printf("What two numbers do you want to add?: ");
            float num_one;
            float num_two;
            fscanf(stdin, "%f %f", &num_one, &num_two);
            printf("The sum is %f\n", num_one + num_two);
        }
        else if(strcmp(user_in, SUB) == 0) {
            printf("What two numbers do you want to subtract?: ");
            float num_one;
            float num_two;
            fscanf(stdin, "%f %f", &num_one, &num_two);
            printf("The difference is %f\n", num_one - num_two);
        }
        else if(strcmp(user_in, MULT) == 0) {
            printf("What two numbers do you want to multiply?: ");
            float num_one;
            float num_two;
            fscanf(stdin, "%f %f", &num_one, &num_two);
            printf("The product is %f\n", num_one * num_two);
        }
        else if(strcmp(user_in, DIV) == 0) {
            printf("What two numbers do you want to divide?: ");
            float num_one;
            float num_two;
            fscanf(stdin, "%f %f", &num_one, &num_two);
            printf("The quotient is %f\n", num_one / num_two);
        }
        else if(strcmp(user_in, "\n") == 0) {
            print_prompt = 0;
        }
        else {
            printf("Unknown command\n");
        }
    }
    printf("Bye Bye!\n");
    return 0;
}
