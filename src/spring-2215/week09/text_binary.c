#include <stdio.h>


int main() {

    // Write as text
    FILE* temp = fopen("temp.txt", "w");
    fprintf(temp, "%d", 12);
    fclose(temp);

    // Read as binary
    temp = fopen("temp.txt", "r");
    char num;
    fread(&num, sizeof(int), 1, temp);
    printf("The value read in was %d\n", num);
    fclose(temp);


    return 0;
}
