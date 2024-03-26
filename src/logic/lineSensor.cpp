//
// Created by Gjorg on 05/03/2024.
//
#include "lineSensor.h"

void enableSensor() {
    pinMode(LINE_SENSOR_0, INPUT_PULLUP);
    pinMode(LINE_SENSOR_1, INPUT_PULLUP);
    pinMode(LINE_SENSOR_2, INPUT_PULLUP);
    pinMode(LINE_SENSOR_3, INPUT_PULLUP);
    pinMode(LINE_SENSOR_4, INPUT_PULLUP);
}

bool scans[2][5] = {
        {W, W, W, W, W}, // previous value
        {W, W, W, W, W} // current value
};

bool _scan[5] = {W, W, W, W, W};

bool equal(const bool scanA[5], const bool scanB[5]);

void scan() {
    bool currentScan[5];
    _scan[0] = digitalRead(LINE_SENSOR_0);
    _scan[1] = digitalRead(LINE_SENSOR_1);
    _scan[2] = digitalRead(LINE_SENSOR_2);
    _scan[3] = digitalRead(LINE_SENSOR_3);
    _scan[4] = digitalRead(LINE_SENSOR_4);

//    for (bool i : currentScan) {
//        Serial.print(i);
//    }
//    Serial.println("");
//
//    if (!equal(scans[1], currentScan)) {
//        // Shift previous scan to make room for the new one
//        for (int i = 0; i < 5; ++i) {
//            scans[0][i] = scans[1][i];
//        }
//        // Store the current scan
//        for (int i = 0; i < 5; ++i) {
//            scans[1][i] = currentScan[i];
//        }
//    }
}

bool sensor(bool i0, bool i1, bool i2, bool i3, bool i4) {
    return _scan[0] == i0
           && _scan[1] == i1
           && _scan[2] == i2
           && _scan[3] == i3
           && _scan[4] == i4;
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