//
// Created by Gjorg on 13/03/2024.
//
#include "SegmentDisplays.h"

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

void resetDisplays() {
    delay(5);
    selectDisplay(0);
    writeDisplay(-2);
    delay(5);
    selectDisplay(1);
    writeDisplay(-2);
}

/**
 * Show a number on the 7-segment displays
 * Takes 10 ms
 * @param value the number to show
 */
void writeDisplays(int value) {
    delay(5);

    selectDisplay(0);
    int dec = value / 10;
    if (dec == 0) {
        writeDisplay(-1);
    } else {
        writeDisplay(dec);
    }

    delay(5);
    selectDisplay(1);
    writeDisplay(value % 10);
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
        digitalWrite(0, LOW);
        digitalWrite(1, HIGH);
    // Set to display 1
    } else {
        digitalWrite(1, LOW);
        digitalWrite(0, HIGH);
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