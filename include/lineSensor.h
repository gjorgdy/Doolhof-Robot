//
// Created by Gjorg on 05/03/2024.
//

#ifndef UNTITLED_LINESENSOR_H
#define UNTITLED_LINESENSOR_H

#include "Arduino.h"

#define W true
#define B false

#define sen0 A0
#define sen1 A1
#define sen2 A2
#define sen3 A3
#define sen4 A4

void scan();
bool sensor(bool, bool, bool, bool, bool);
bool lastSensor(bool, bool, bool, bool, bool);
void enableSensor();

#endif //UNTITLED_LINESENSOR_H
