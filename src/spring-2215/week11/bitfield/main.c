/**
 * Example of how to decompose encoded data using bitfields and unions.
 *
 * The incoming data is in the form
 *
 * |        8 Bytes        |     2 bits     |      2 bit     |      1 bit       | 3 bits   |
 * | Voltage in deci volts | Voltage health | Charging State | Temperature Safe | Reserved |
 *
 * Voltage in Deci Volts
 * =====================
 * The voltage measured in deci volts. For example, a value of 30 represents
 * 3 Volts.
 *
 *
 * Voltage Health
 * ==============
 * Indicates the state of the battery
 *
 * 11: Reserved
 * 10: Over voltage
 * 01: Under voltage
 * 00: Healthy
 *
 * Charging State
 * ==============
 * Indicates if the batteries are charging or discharging
 *
 * 11: Reserved
 * 10: Discharging
 * 01: Charging
 * 00: Static
 *
 * Temperature Safe
 * ================
 * Flag that represents if the batteries are in a safe state
 * 1: Unsafe
 * 0: Safe
 */
#include <stdio.h>

struct battery_state {
    unsigned char reserved : 3;
    unsigned char temperature_safe : 1;
    unsigned char charging_state : 2;
    unsigned char voltage_health : 2;
    unsigned char voltage : 8;
};

union convertion {
    unsigned short input;
    struct battery_state state;
};

void print_details(struct battery_state* state) {
    printf("Voltage: %.1f\n", (float)state->voltage / 10);

    // Print health information
    if (state->voltage_health == 0) {
        printf("Battery healthy\n");
    } else if (state->voltage_health == 1) {
        printf("Under voltage\n");
    } else if (state->voltage_health == 2) {
        printf("Over voltage\n");
    } else {
        printf("Unknown battery state\n");
    }

    // Print charging state
    if (state->charging_state == 0) {
        printf("Static state\n");
    } else if (state->charging_state == 1) {
        printf("Charging state\n");
    } else if (state->charging_state == 2) {
        printf("Discharging state\n");
    } else {
        printf("Unknown state\n");
    }

    // Print temperature state
    if (state->temperature_safe == 0) {
        printf("Temperature OK\n");
    } else {
        printf("Temperature dangerous\n");
    }
}


int main() {
    union convertion convert;

    // 2.5 volts, healthy, discharging, temp ok
    unsigned short example_one = 0x1920;
    convert.input = example_one;
    print_details(&convert.state);

    printf("\n");

    // 4.5 volts, over voltage, charging, temp bad
    unsigned short example_two = 0x2D98;
    convert.input = example_two;
    print_details(&convert.state);

    return 0;
}
