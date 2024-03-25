//
// Created by Gjorg on 25/03/2024.
//

#ifndef DOOLHOFROBOT_PINS_H
#define DOOLHOFROBOT_PINS_H

#include <Arduino.h>

// ping sonar
#define SONAR_TRIG 2
#define SONAR_ECHO A5

// seven segment
#define DISPLAY_A 10
#define DISPLAY_B 9
#define DISPLAY_C 8
#define DISPLAY_D 7
#define DISPLAY_E 6
#define DISPLAY_F 5
#define DISPLAY_G 4
#define DISPLAY_GROUND_0 0
#define DISPLAY_GROUND_1 1

// motor shield
#define MOTOR_DIRECTION_A 12
#define MOTOR_DIRECTION_B 13
#define MOTOR_PWM_A 3
#define MOTOR_PWM_B 11

// line sensor
#define LINE_SENSOR_0 A0
#define LINE_SENSOR_1 A1
#define LINE_SENSOR_2 A2
#define LINE_SENSOR_3 A3
#define LINE_SENSOR_4 A4

#endif //DOOLHOFROBOT_PINS_H
