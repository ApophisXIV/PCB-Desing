#include <Arduino.h>

#include "../include/keypad_4x4.h"

const int keypad_pins[]    = {PIN7, PIN6, PIN5, PIN4, PIN3, PIN2, PIN_A0, PIN_A1};
const int keypad_pins_size = sizeof(keypad_pins) / sizeof(keypad_pins[0]);
const int buzzer_pin       = PIN_A5;

void setup() {
    Serial.begin(115200);
    init_keypad(keypad_pins, keypad_pins_size);
    pinMode(buzzer_pin, OUTPUT);
}

void buzzer_beep() {
    digitalWrite(buzzer_pin, 1);
    delay(5);
    digitalWrite(buzzer_pin, 0);
}

void loop() {
    char key = read_keypad(keypad_pins, keypad_pins_size, buzzer_beep);
    if (key != NO_KEY_PRESSED) Serial.println(key);
}
