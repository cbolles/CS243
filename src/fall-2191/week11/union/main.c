/**
 * file: main.c
 *
 * Unions are similar to structures except that all the members share the same physical space
 * in memory. This has a few uses, commonly you will see it when you have to unpack data that
 * may be compressed in other manners. This example shows how you can store a "secret message" using
 * a union.
 *
 * @author Collin Bolles
 */
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

union message_u {
    long encoded[3];
    char string[24];
};

typedef union message_u Message;

/**
 * Encodes the given message into a union that contains the long representation and the char
 * representation
 * @param secret_message The string message to encode, cannot be greater then 23 bytes long
 * @return The message with the original message and the encoding
 */
Message *encode_message(char *secret_message) {
    // Cannot encode a message bigger then 24 bytes long
    assert(strlen(secret_message) + 1 <= 24);

    // Create the message. I want everything to be initalized to zero
    Message *message = malloc(sizeof(Message));
    message->encoded[0] = message->encoded[1] = message->encoded[2] = 0;;
    strcpy(message->string, secret_message);

   return message;
}

void print_encoding(Message *message) {
    printf("Encoded message: %ld %ld %ld\n", message->encoded[0], message->encoded[1], message->encoded[2]);
}

void print_string(Message *message) {
    printf("Decoded message: %s\n", message->string);
}

int main() {
    Message *encoded_message = encode_message("Good luck on exam 2!");

    print_encoding(encoded_message);
    print_string(encoded_message);

    free(encoded_message);

    Message new_message;
    new_message.encoded[0] = 7166753268409790279;
    new_message.encoded[1] = 7023474808850423915;
    new_message.encoded[2] = 556933229;
    printf("The message is %s\n", new_message.string);

    return 0;
}
