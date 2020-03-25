/**
 * Bitwise operators are really common when working at the lower level since lots of communication
 * with hardware requires "packing" and "unpacking" dense data. In this example we will work with
 * packing data into and out of an int.
 *     ---------------------------------------  
 *    |  Num_3  |  Num_2  |  Num_1  |  Num_0  |
 *     ---------------------------------------
 * A single int can really hold 4 1 byte values in it. We will see how to pack and unpack data
 * using bitwise data.
 */

#include <stdio.h>

/**
 * Converts a single int into an array of 4 bytes.
 * @param packed The packed int to extract the values from
 * @param unpacked The unpacked numbers
 */
void unpack(int packed, char unpacked[4]) {
    unpacked[0] = (packed >> 0) & 0xFF;
    unpacked[1] = (packed >> 8) & 0xFF;
    unpacked[2] = (packed >> 16) & 0xFF;
    unpacked[3] = (packed >> 24) & 0xFF;
}

/**
 * Converts the unpacked data into a packed data int
 * @param packed Pointer to the packed data
 * @param unpacked The unpacked numbers
 */
void pack(int *packed, char unpacked[4]) {
    int new_value = 0;
    
    new_value |= (unpacked[0] & 0xFF) << 0;
    new_value |= (unpacked[1] & 0xFF) << 8;
    new_value |= (unpacked[2] & 0xFF) << 16;
    new_value |= (unpacked[3] & 0xFF) << 24;

    *packed = new_value;
}

void print_data(int packed, char unpacked[4]) {
    printf("Packed Data: %#010X \n", packed);
    for(int i = 0; i < 4; i++)
        printf("Unpacked[%d] = %#04X\n", i, unpacked[i] & 0xFF);
}

int main() {
    int packed = 0x1545BC34;
    char unpacked[4];

    // Unpack the original values   
    unpack(packed, unpacked);
    print_data(packed, unpacked);

    // Update the unpacked values and repack
    unpacked[0] = 0x16;
    pack(&packed, unpacked);
    
    print_data(packed, unpacked);
    return 0;
}
