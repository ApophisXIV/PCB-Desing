#ifndef KEYPAD_4X4_H
#define KEYPAD_4X4_H

#include <Arduino.h>

#define NO_KEY_PRESSED 0

void init_keypad(const int keypad_pins[], const size_t keypad_pins_size);
char read_keypad(const int keypad_pins[], const size_t keypad_pins_size, void (*buzzer_beep)() = NULL);

#endif    // KEYPAD_4X4_H