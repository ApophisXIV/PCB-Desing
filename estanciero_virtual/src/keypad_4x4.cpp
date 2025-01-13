#include "../include/keypad_4x4.h"

void init_keypad(const int keypad_pins[], size_t keypad_pins_size) {
    for (size_t i = 0; i < keypad_pins_size; i++)
        pinMode(keypad_pins[i], i < 4 ? OUTPUT : INPUT_PULLUP);
}

const char lut_teclado[][4] = {
    {'1', '2', '3', 'A'},
    {'4', '5', '6', 'B'},
    {'7', '8', '9', 'C'},
    {'*', '0', '#', 'D'},
};

char read_keypad(const int keypad_pins[], size_t keypad_pins_size, void (*buzzer_beep)()) {

    static unsigned long last_time = 0;

    for (size_t x = 0; x < keypad_pins_size / 2; x++) {
        for (size_t y = 0; y < keypad_pins_size / 2; y++) {

            PORTD &= 0x0F;
            PORTD |= ~(1 << (7 - y)) & 0xF0;

            if (!digitalRead(keypad_pins[x + keypad_pins_size / 2]) && last_time + 400 < millis()) {
                last_time = millis();
                if (buzzer_beep != NULL) buzzer_beep();
                return lut_teclado[y][x];
            }
        }
    }

    return NO_KEY_PRESSED;
}
