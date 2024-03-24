//
// Created by Gjorg on 05/03/2024.
//
#include "lineSensor.h"

void enableSensor() {
    pinMode(sen0, INPUT_PULLUP);
    pinMode(sen1, INPUT_PULLUP);
    pinMode(sen2, INPUT_PULLUP);
    pinMode(sen3, INPUT_PULLUP);
    pinMode(sen4, INPUT_PULLUP);
}

bool scans[2][5] = {
        {W, W, W, W, W}, // previous value
        {W, W, W, W, W} // current value
};

bool equal(const bool scanA[5], const bool scanB[5]);

void scan() {
    bool currentScan[5];
    currentScan[0] = digitalRead(sen0);
    currentScan[1] = digitalRead(sen1);
    currentScan[2] = digitalRead(sen2);
    currentScan[3] = digitalRead(sen3);
    currentScan[4] = digitalRead(sen4);

//    for (bool i : currentScan) {
//        Serial.print(i);
//    }
//    Serial.println("");

    if (!equal(scans[1], currentScan)) {
        // Shift previous scan to make room for the new one
        for (int i = 0; i < 5; ++i) {
            scans[0][i] = scans[1][i];
        }
        // Store the current scan
        for (int i = 0; i < 5; ++i) {
            scans[1][i] = currentScan[i];
        }
    }
}

bool sensor(bool i0, bool i1, bool i2, bool i3, bool i4) {
    return scans[1][0] == i0
           && scans[1][1] == i1
           && scans[1][2] == i2
           && scans[1][3] == i3
           && scans[1][4] == i4;
}

bool lastSensor(bool i0, bool i1, bool i2, bool i3, bool i4) {
    return scans[0][0] == i0
           && scans[0][1] == i1
           && scans[0][2] == i2
           && scans[0][3] == i3
           && scans[0][4] == i4;
}

bool equal(const bool scanA[5], const bool scanB[5]) {
    return scanA[0] == scanB[0] &&
           scanA[1] == scanB[1] &&
           scanA[2] == scanB[2] &&
           scanA[3] == scanB[3] &&
           scanA[4] == scanB[4];
}