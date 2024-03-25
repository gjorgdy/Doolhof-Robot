//
// Created by Gjorg on 24/03/2024.
//

#include "pathSave.h"

// Path values;
//  L - Go left
//  R - Go right
//  S - Go straight
//  T - Turn around

// EEPROM storage
// 0  -> state
// 1  -> path string length
// 2+ -> path string

String path = "";

void writePath() {
    Serial.println("writing le path");
    String optimized = optimize(path);
    int length = optimized.length();
    EEPROM.write(1, length); // Store the string length
    for (int i = 0; i < length; i++) {
        EEPROM.write(i + 2, optimized[i]);
    }
}

String readPath() {
    int len = EEPROM.read(1);
    char myString[len];
    for (int i = 0; i < len; i++) {
        myString[i] = EEPROM.read(i + 2);
    }
    return myString;
}

void writeState(const int state) {
    EEPROM.write(0, state);
}

int readState() {
    return EEPROM.read(0);
}

/**
 * Set whole EEPROM back to all 255
 */
void resetEEPROM() {
    EEPROM.write(0, 0);
    EEPROM.write(1, 0);
    for (uint16_t i = 2 ; i < EEPROM.length() ; i++) {
        if (EEPROM.read(i) != 255) {
            EEPROM.write(i, 255);
        }
    }
}

//
// PATH HANDLING
//

void addAction(char c) {
    path.concat(c);
}

void replace(char* str, const char* from, const char* to) {
    int start_pos = 0;
    int from_len = strlen(from);
    int to_len = strlen(to);
    if ((start_pos = strstr(str + start_pos, from) - str) != -1) {
        memmove(str + start_pos + to_len, str + start_pos + from_len, strlen(str + start_pos + from_len) + 1);
        memcpy(str + start_pos, to, to_len);
    }
}

String optimize(String in) {
    replace(in.begin(), " ", "");
    while (in.indexOf('T') != -1) {
        Serial.println(in);
        replace(in.begin(), "LTL", "S");
        replace(in.begin(), "RTL", "T");
        replace(in.begin(), "STS", "T");
        replace(in.begin(), "STL", "R");
        replace(in.begin(), "LTS", "R");
        replace(in.begin(), "LTR", "T");
    }
    return in;
}

