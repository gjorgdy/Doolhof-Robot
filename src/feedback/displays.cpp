//
// Created by Gjorg on 13/03/2024.
//

#include "displays.h"

/**
 * Enable the correct pins
 */
void enableDisplays() {
    // Display
    pinMode(DISPLAY_A, OUTPUT);
    pinMode(DISPLAY_B, OUTPUT);
    pinMode(DISPLAY_C, OUTPUT);
    pinMode(DISPLAY_D, OUTPUT);
    pinMode(DISPLAY_E, OUTPUT);
    pinMode(DISPLAY_F, OUTPUT);
    pinMode(DISPLAY_G, OUTPUT);
    // Display ground
    pinMode(DISPLAY_GROUND_0, OUTPUT);
    pinMode(DISPLAY_GROUND_1, OUTPUT);
}

/**
 * Select a display to write to
 * @param display the display to write to
 */
void selectDisplay(int display) {
    // Clear previous frame
    writeDisplay(-1);
    // Set to display 0
    if (display == 0) {
        digitalWrite(DISPLAY_GROUND_0, LOW);
        digitalWrite(DISPLAY_GROUND_1, HIGH);
    // Set to display 1
    } else {
        digitalWrite(DISPLAY_GROUND_0, HIGH);
        digitalWrite(DISPLAY_GROUND_1, LOW);
    }
}

/**
 * Show a number on the 7-segment displays
 * Takes 10 ms
 * @param number the number to show
 */
void writeDisplays(int number) {
    // Frame rate of 1000/5 = 200hz
    delay(1);
    // Select first display
    selectDisplay(0);
    // Calculate first digit
    int dec = number / 10;
    // Don't show anything if it's 0
    if (dec == 0) {
        writeDisplay(-1);
    // Show the digit
    } else {
        writeDisplay(dec);
    }
    // Frame rate of 1000/5 = 200hz
    delay(1);
    // Select second display
    selectDisplay(1);
    // Print second digit
    writeDisplay(number % 10);
}

void writeDisplays(const String& string) {
    // Frame rate of 1000/5 = 200hz
    delay(1);
    // Select first display
    selectDisplay(0);
    // Print first character
    writeDisplay(string.charAt(0));
    // Frame rate of 1000/5 = 200hz
    delay(1);
    // Select second display
    selectDisplay(1);
    // Print second character
    writeDisplay(string.charAt(1));
}

void writeDisplay(char character) {
    switch (character) {
        case 's': {
            digitalWrite(DISPLAY_A, HIGH);
            digitalWrite(DISPLAY_B, LOW);
            digitalWrite(DISPLAY_C, HIGH);
            digitalWrite(DISPLAY_D, HIGH);
            digitalWrite(DISPLAY_E, LOW);
            digitalWrite(DISPLAY_F, HIGH);
            digitalWrite(DISPLAY_G, HIGH);
            break;
        } case 't': {
            digitalWrite(DISPLAY_A, LOW);
            digitalWrite(DISPLAY_B, LOW);
            digitalWrite(DISPLAY_C, LOW);
            digitalWrite(DISPLAY_D, HIGH);
            digitalWrite(DISPLAY_E, HIGH);
            digitalWrite(DISPLAY_F, HIGH);
            digitalWrite(DISPLAY_G, HIGH);
            break;
        } case 'f': {
            digitalWrite(DISPLAY_A, HIGH);
            digitalWrite(DISPLAY_B, LOW);
            digitalWrite(DISPLAY_C, LOW);
            digitalWrite(DISPLAY_D, LOW);
            digitalWrite(DISPLAY_E, HIGH);
            digitalWrite(DISPLAY_F, HIGH);
            digitalWrite(DISPLAY_G, HIGH);
            break;
        } case 'i': {
            digitalWrite(DISPLAY_A, LOW);
            digitalWrite(DISPLAY_B, LOW);
            digitalWrite(DISPLAY_C, LOW);
            digitalWrite(DISPLAY_D, LOW);
            digitalWrite(DISPLAY_E, HIGH);
            digitalWrite(DISPLAY_F, HIGH);
            digitalWrite(DISPLAY_G, LOW);
            break;
        } case 'r': {
            digitalWrite(DISPLAY_A, HIGH);
            digitalWrite(DISPLAY_B, LOW);
            digitalWrite(DISPLAY_C, LOW);
            digitalWrite(DISPLAY_D, LOW);
            digitalWrite(DISPLAY_E, HIGH);
            digitalWrite(DISPLAY_F, HIGH);
            digitalWrite(DISPLAY_G, LOW);
            break;
        } case 'e': {
            digitalWrite(DISPLAY_A, HIGH);
            digitalWrite(DISPLAY_B, HIGH);
            digitalWrite(DISPLAY_C, LOW);
            digitalWrite(DISPLAY_D, HIGH);
            digitalWrite(DISPLAY_E, HIGH);
            digitalWrite(DISPLAY_F, HIGH);
            digitalWrite(DISPLAY_G, HIGH);
            break;
        } default: {
            digitalWrite(DISPLAY_A, LOW);
            digitalWrite(DISPLAY_B, LOW);
            digitalWrite(DISPLAY_C, LOW);
            digitalWrite(DISPLAY_D, LOW);
            digitalWrite(DISPLAY_E, LOW);
            digitalWrite(DISPLAY_F, LOW);
            digitalWrite(DISPLAY_G, HIGH);
            break;
        }
    }
}

/**
 * Write a single digit to the selected display
 *
 * Special values :
 *  -2 : only show middle line
 *  -1 : empty the display
 * @param value
 */
void writeDisplay(int value) {
    if (value == -2) {
        digitalWrite(DISPLAY_A, LOW);
        digitalWrite(DISPLAY_B, LOW);
        digitalWrite(DISPLAY_C, LOW);
        digitalWrite(DISPLAY_D, LOW);
        digitalWrite(DISPLAY_E, LOW);
        digitalWrite(DISPLAY_F, LOW);
        digitalWrite(DISPLAY_G, HIGH);
    } else if (value == -1) {
        digitalWrite(DISPLAY_A, LOW);
        digitalWrite(DISPLAY_B, LOW);
        digitalWrite(DISPLAY_C, LOW);
        digitalWrite(DISPLAY_D, LOW);
        digitalWrite(DISPLAY_E, LOW);
        digitalWrite(DISPLAY_F, LOW);
        digitalWrite(DISPLAY_G, LOW);
    } else if (value == 0) {
        digitalWrite(DISPLAY_A, HIGH);
        digitalWrite(DISPLAY_B, HIGH);
        digitalWrite(DISPLAY_C, HIGH);
        digitalWrite(DISPLAY_D, HIGH);
        digitalWrite(DISPLAY_E, HIGH);
        digitalWrite(DISPLAY_F, HIGH);
        digitalWrite(DISPLAY_G, LOW);
    } else if (value == 1) {
        digitalWrite(DISPLAY_A, LOW);
        digitalWrite(DISPLAY_B, HIGH);
        digitalWrite(DISPLAY_C, HIGH);
        digitalWrite(DISPLAY_D, LOW);
        digitalWrite(DISPLAY_E, LOW);
        digitalWrite(DISPLAY_F, LOW);
        digitalWrite(DISPLAY_G, LOW);
    } else if (value == 2) {
        digitalWrite(DISPLAY_A, HIGH);
        digitalWrite(DISPLAY_B, HIGH);
        digitalWrite(DISPLAY_C, LOW);
        digitalWrite(DISPLAY_D, HIGH);
        digitalWrite(DISPLAY_E, HIGH);
        digitalWrite(DISPLAY_F, LOW);
        digitalWrite(DISPLAY_G, HIGH);
    } else if (value == 3) {
        digitalWrite(DISPLAY_A, HIGH);
        digitalWrite(DISPLAY_B, HIGH);
        digitalWrite(DISPLAY_C, HIGH);
        digitalWrite(DISPLAY_D, HIGH);
        digitalWrite(DISPLAY_E, LOW);
        digitalWrite(DISPLAY_F, LOW);
        digitalWrite(DISPLAY_G, HIGH);
    } else if (value == 4) {
        digitalWrite(DISPLAY_A, LOW);
        digitalWrite(DISPLAY_B, HIGH);
        digitalWrite(DISPLAY_C, HIGH);
        digitalWrite(DISPLAY_D, LOW);
        digitalWrite(DISPLAY_E, LOW);
        digitalWrite(DISPLAY_F, HIGH);
        digitalWrite(DISPLAY_G, HIGH);
    } else if (value == 5) {
        digitalWrite(DISPLAY_A, HIGH);
        digitalWrite(DISPLAY_B, LOW);
        digitalWrite(DISPLAY_C, HIGH);
        digitalWrite(DISPLAY_D, HIGH);
        digitalWrite(DISPLAY_E, LOW);
        digitalWrite(DISPLAY_F, HIGH);
        digitalWrite(DISPLAY_G, HIGH);
    } else if (value == 6) {
        digitalWrite(DISPLAY_A, HIGH);
        digitalWrite(DISPLAY_B, LOW);
        digitalWrite(DISPLAY_C, HIGH);
        digitalWrite(DISPLAY_D, HIGH);
        digitalWrite(DISPLAY_E, HIGH);
        digitalWrite(DISPLAY_F, HIGH);
        digitalWrite(DISPLAY_G, HIGH);
    } else if (value == 7) {
        digitalWrite(DISPLAY_A, HIGH);
        digitalWrite(DISPLAY_B, HIGH);
        digitalWrite(DISPLAY_C, HIGH);
        digitalWrite(DISPLAY_D, LOW);
        digitalWrite(DISPLAY_E, LOW);
        digitalWrite(DISPLAY_F, LOW);
        digitalWrite(DISPLAY_G, LOW);
    } else if (value == 8) {
        digitalWrite(DISPLAY_A, HIGH);
        digitalWrite(DISPLAY_B, HIGH);
        digitalWrite(DISPLAY_C, HIGH);
        digitalWrite(DISPLAY_D, HIGH);
        digitalWrite(DISPLAY_E, HIGH);
        digitalWrite(DISPLAY_F, HIGH);
        digitalWrite(DISPLAY_G, HIGH);
    } else if (value == 9) {
        digitalWrite(DISPLAY_A, HIGH);
        digitalWrite(DISPLAY_B, HIGH);
        digitalWrite(DISPLAY_C, HIGH);
        digitalWrite(DISPLAY_D, HIGH);
        digitalWrite(DISPLAY_E, LOW);
        digitalWrite(DISPLAY_F, HIGH);
        digitalWrite(DISPLAY_G, HIGH);
    }
}

/**
 * Set displays to default stand
 */
void resetDisplays() {
    // Enable both displays
    digitalWrite(DISPLAY_GROUND_0, LOW);
    digitalWrite(DISPLAY_GROUND_1, LOW);
    // Write middle line
    writeDisplay(-2);
}

/**
 * Set displays to empty
 */
void emptyDisplays() {
    // Enable both displays
    digitalWrite(DISPLAY_GROUND_1, LOW);
    digitalWrite(DISPLAY_GROUND_0, LOW);
    // Make displays empty
    writeDisplay(-1);
}