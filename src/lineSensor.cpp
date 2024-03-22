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

int i = 0;
bool sensed[5][5];
bool medSensed[5];

void scan() {
    sensed[i][0] = digitalRead(sen4);
    sensed[i][1] = digitalRead(sen3);
    sensed[i][2] = digitalRead(sen2);
    sensed[i][3] = digitalRead(sen1);
    sensed[i][4] = digitalRead(sen0);
    // Store medians in medSensed
    if (i == 5) {
        for (int j = 0 ; j < 5 ; j++) {
            int trues = 0;
            for (int k = 0 ; k < 5 ; k++) {
                if (sensed[j][k]) trues++;
            }
            medSensed[j] = trues > 2;
        }
    } else {
        i++;
    }
}

bool sensor(bool i0, bool i1, bool i2, bool i3, bool i4) {
    return medSensed[0] == i0
           && medSensed[1] == i1
           && medSensed[2] == i2
           && medSensed[3] == i3
           && medSensed[4] == i4;
//    return i1 == digitalRead(sen4) &&
//       i2 == digitalRead(sen3) &&
//       i3 == digitalRead(sen2) &&
//       i4 == digitalRead(sen1) &&
//       i5 == digitalRead(sen0);
}