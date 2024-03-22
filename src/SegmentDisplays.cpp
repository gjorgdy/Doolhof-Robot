//
// Created by Gjorg on 13/03/2024.
//

#include "SegmentDisplays.h"

void counter() {

}

/**
 * Enable the correct pins
 */
void enableDisplays() {
    // Display
    pinMode(segA, OUTPUT);
    pinMode(segB, OUTPUT);
    pinMode(segC, OUTPUT);
    pinMode(segD, OUTPUT);
    pinMode(segE, OUTPUT);
    pinMode(segF, OUTPUT);
    pinMode(segG, OUTPUT);
    // Display ground
    pinMode(gnd0, OUTPUT);
    pinMode(gnd1, OUTPUT);
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
        digitalWrite(gnd0, LOW);
        digitalWrite(gnd1, HIGH);
    // Set to display 1
    } else {
        digitalWrite(gnd0, HIGH);
        digitalWrite(gnd1, LOW);
    }
}

/**
 * Show a number on the 7-segment displays
 * Takes 10 ms
 * @param number the number to show
 */
void writeDisplays(int number) {
    // Frame rate of 1000/5 = 200hz
    delay(2);
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
    delay(2);
    // Select second display
    selectDisplay(1);
    // Print second digit
    writeDisplay(number % 10);
}

void writeDisplays(const String& string) {
    // Frame rate of 1000/5 = 200hz
    delay(5);
    // Select first display
    selectDisplay(0);
    // Print first character
    writeDisplay(string.charAt(0));
    // Frame rate of 1000/5 = 200hz
    delay(5);
    // Select second display
    selectDisplay(1);
    // Print second character
    writeDisplay(string.charAt(1));
}

void writeDisplay(char character) {
    switch (character) {
        case 's': {
            digitalWrite(segA, HIGH);
            digitalWrite(segB, LOW);
            digitalWrite(segC, HIGH);
            digitalWrite(segD, HIGH);
            digitalWrite(segE, LOW);
            digitalWrite(segF, HIGH);
            digitalWrite(segG, HIGH);
            break;
        } case 't': {
            digitalWrite(segA, LOW);
            digitalWrite(segB, LOW);
            digitalWrite(segC, LOW);
            digitalWrite(segD, HIGH);
            digitalWrite(segE, HIGH);
            digitalWrite(segF, HIGH);
            digitalWrite(segG, HIGH);
            break;
        } case 'f': {
            digitalWrite(segA, HIGH);
            digitalWrite(segB, LOW);
            digitalWrite(segC, LOW);
            digitalWrite(segD, LOW);
            digitalWrite(segE, HIGH);
            digitalWrite(segF, HIGH);
            digitalWrite(segG, HIGH);
            break;
        } case 'i': {
            digitalWrite(segA, LOW);
            digitalWrite(segB, LOW);
            digitalWrite(segC, LOW);
            digitalWrite(segD, LOW);
            digitalWrite(segE, HIGH);
            digitalWrite(segF, HIGH);
            digitalWrite(segG, LOW);
            break;
        } default: {
            digitalWrite(segA, LOW);
            digitalWrite(segB, LOW);
            digitalWrite(segC, LOW);
            digitalWrite(segD, LOW);
            digitalWrite(segE, LOW);
            digitalWrite(segF, LOW);
            digitalWrite(segG, HIGH);
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
        digitalWrite(segA, LOW);
        digitalWrite(segB, LOW);
        digitalWrite(segC, LOW);
        digitalWrite(segD, LOW);
        digitalWrite(segE, LOW);
        digitalWrite(segF, LOW);
        digitalWrite(segG, HIGH);
    } else if (value == -1) {
        digitalWrite(segA, LOW);
        digitalWrite(segB, LOW);
        digitalWrite(segC, LOW);
        digitalWrite(segD, LOW);
        digitalWrite(segE, LOW);
        digitalWrite(segF, LOW);
        digitalWrite(segG, LOW);
    } else if (value == 0) {
        digitalWrite(segA, HIGH);
        digitalWrite(segB, HIGH);
        digitalWrite(segC, HIGH);
        digitalWrite(segD, HIGH);
        digitalWrite(segE, HIGH);
        digitalWrite(segF, HIGH);
        digitalWrite(segG, LOW);
    } else if (value == 1) {
        digitalWrite(segA, LOW);
        digitalWrite(segB, HIGH);
        digitalWrite(segC, HIGH);
        digitalWrite(segD, LOW);
        digitalWrite(segE, LOW);
        digitalWrite(segF, LOW);
        digitalWrite(segG, LOW);
    } else if (value == 2) {
        digitalWrite(segA, HIGH);
        digitalWrite(segB, HIGH);
        digitalWrite(segC, LOW);
        digitalWrite(segD, HIGH);
        digitalWrite(segE, HIGH);
        digitalWrite(segF, LOW);
        digitalWrite(segG, HIGH);
    } else if (value == 3) {
        digitalWrite(segA, HIGH);
        digitalWrite(segB, HIGH);
        digitalWrite(segC, HIGH);
        digitalWrite(segD, HIGH);
        digitalWrite(segE, LOW);
        digitalWrite(segF, LOW);
        digitalWrite(segG, HIGH);
    } else if (value == 4) {
        digitalWrite(segA, LOW);
        digitalWrite(segB, HIGH);
        digitalWrite(segC, HIGH);
        digitalWrite(segD, LOW);
        digitalWrite(segE, LOW);
        digitalWrite(segF, HIGH);
        digitalWrite(segG, HIGH);
    } else if (value == 5) {
        digitalWrite(segA, HIGH);
        digitalWrite(segB, LOW);
        digitalWrite(segC, HIGH);
        digitalWrite(segD, HIGH);
        digitalWrite(segE, LOW);
        digitalWrite(segF, HIGH);
        digitalWrite(segG, HIGH);
    } else if (value == 6) {
        digitalWrite(segA, HIGH);
        digitalWrite(segB, LOW);
        digitalWrite(segC, HIGH);
        digitalWrite(segD, HIGH);
        digitalWrite(segE, HIGH);
        digitalWrite(segF, HIGH);
        digitalWrite(segG, HIGH);
    } else if (value == 7) {
        digitalWrite(segA, HIGH);
        digitalWrite(segB, HIGH);
        digitalWrite(segC, HIGH);
        digitalWrite(segD, LOW);
        digitalWrite(segE, LOW);
        digitalWrite(segF, LOW);
        digitalWrite(segG, LOW);
    } else if (value == 8) {
        digitalWrite(segA, HIGH);
        digitalWrite(segB, HIGH);
        digitalWrite(segC, HIGH);
        digitalWrite(segD, HIGH);
        digitalWrite(segE, HIGH);
        digitalWrite(segF, HIGH);
        digitalWrite(segG, HIGH);
    } else if (value == 9) {
        digitalWrite(segA, HIGH);
        digitalWrite(segB, HIGH);
        digitalWrite(segC, HIGH);
        digitalWrite(segD, HIGH);
        digitalWrite(segE, LOW);
        digitalWrite(segF, HIGH);
        digitalWrite(segG, HIGH);
    }
}

/**
 * Set displays to default stand
 */
void resetDisplays() {
    // Enable both displays
    digitalWrite(gnd0, LOW);
    digitalWrite(gnd1, LOW);
    // Write middle line
    writeDisplay(-2);
}

/**
 * Set displays to empty
 */
void emptyDisplays() {
    // Enable both displays
    digitalWrite(gnd1, LOW);
    digitalWrite(gnd0, LOW);
    // Make displays empty
    writeDisplay(-1);
}