/**
 * Predefines can be helpful in code, but they are evaluated only when the c
 * preprocessor runs.
 *
 * @author Collin Bolles
 */
#include <stdio.h>

int main() {
    // Print the file name
    printf("__FILE__ = %s\n", __FILE__);
	printf("__DATE__ = %s\n", __DATE__);
	printf("__TIME__ = %s\n", __TIME__);
}
