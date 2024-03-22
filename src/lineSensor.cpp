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

bool sensor(bool i1, bool i2, bool i3, bool i4, bool i5) {
    return i1 == digitalRead(sen4) &&
       i2 == digitalRead(sen3) &&
       i3 == digitalRead(sen2) &&
       i4 == digitalRead(sen1) &&
       i5 == digitalRead(sen0);
}