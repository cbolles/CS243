/**
 * Unions can also be used to convert to and from packed data just in a little differnt way. Below
 * is an example of packing an unpacking using unions.
 */

#include <stdio.h>

/**
 * Union between the shared data packed together
 */
union convert {
    int packed;
    char unpacked[4];
};

void print_data(union convert convert) {
    printf("Packed Data: %#010X \n", convert.packed);
    for(int i = 0; i < 4; i++)
        printf("Unpacked[%d] = %#04X\n", i, convert.unpacked[i] & 0xFF);
}

int main() {
    union convert convert;
    convert.packed =  0x1545BC34;
    print_data(convert);

    convert.unpacked[0] = 0x16;
    print_data(convert);

    return 0;
}
