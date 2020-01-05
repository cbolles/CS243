#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>

int read_acc() {
    srand(time(0));
    return rand();
}

int get_status(int raw_value) {
    return (raw_value >> 24) & 255;
}

int get_x_acc(int raw_value) {
    return (raw_value >> 16) & 255;
}

int get_y_acc(int raw_value) {
    return (raw_value >> 8) & 255;
}

int get_z_acc(int raw_value) {
    return raw_value & 255;
}

int main() {
      uint32_t raw_value = read_acc(); // Assume this returns the value from the accelerometer
      uint8_t status = get_status(raw_value);
      uint8_t x_acc = get_x_acc(raw_value);
      uint8_t y_acc = get_y_acc(raw_value);
      uint8_t z_acc = get_z_acc(raw_value);

      printf("The original value was %#010X\n", raw_value);
      printf("The status was %#4X\n", status);
      printf("The x_acc was %#4X\n", x_acc);
      printf("The y_acc was %#4X\n", y_acc);
      printf("The z_acc was %#4X\n", z_acc);

      return 0;
}
