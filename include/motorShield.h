//
// Created by Gjorg on 05/03/2024.
//

#ifndef UNTITLED_MOVEMENTS_H
#define UNTITLED_MOVEMENTS_H

#include "lineSensor.h"

#define baseSpeed 80 //120
#define steerDelta (baseSpeed / 2)
#define slightSteerDelta (baseSpeed / 6)

// motor shield
#define dirA 12
#define dirB 13
#define pwmA 3
#define pwmB 11

void setLeftMotor(int speed, bool forward);
void modLeftMotor(int modSpeed, bool forward);
void setRightMotor(int speed, bool forward);
void modRightMotor(int modSpeed, bool forward);

void enableMotors();

#endif //UNTITLED_MOVEMENTS_H
