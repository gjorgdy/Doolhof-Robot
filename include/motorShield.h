//
// Created by Gjorg on 05/03/2024.
//

#ifndef UNTITLED_MOVEMENTS_H
#define UNTITLED_MOVEMENTS_H

#include "pins.h"

#define baseSpeed 80
#define straightSpeed 100
#define steerDelta 30
#define slightSteerDelta 15

void setLeftMotor(int speed, bool forward);
void modLeftMotor(int modSpeed);
void setRightMotor(int speed, bool forward);
void modRightMotor(int modSpeed);

void enableMotors();

#endif //UNTITLED_MOVEMENTS_H
