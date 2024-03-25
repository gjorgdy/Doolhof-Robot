//
// Created by Gjorg on 05/03/2024.
//

#ifndef UNTITLED_LINESENSOR_H
#define UNTITLED_LINESENSOR_H

#include "pins.h"

#define W true
#define B false

void scan();
bool sensor(bool, bool, bool, bool, bool);
bool lastSensor(bool, bool, bool, bool, bool);
void enableSensor();

#endif //UNTITLED_LINESENSOR_H
