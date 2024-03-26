//
// Created by Gjorg on 05/03/2024.
//
#include <Arduino.h>
#include "motorShield.h"
#include "lineSensor.h"

int leftSpeed = 0;
boolean leftForward = true;
int rightSpeed = 0;
boolean rightForward = true;

/*
 * Open pins of motorshield
 */
void enableMotors() {
    pinMode(MOTOR_DIRECTION_A, OUTPUT);
    pinMode(MOTOR_DIRECTION_B, OUTPUT);
    pinMode(MOTOR_PWM_A, OUTPUT);
    pinMode(MOTOR_PWM_B, OUTPUT);
}

void setLeftMotor(int speed, bool forward) {
    analogWrite(MOTOR_PWM_B, speed);
    digitalWrite(MOTOR_DIRECTION_B, forward ? HIGH : LOW);
    leftSpeed = speed;
    leftForward = forward;
}

void modLeftMotor(int modSpeed, bool forward) {
    setLeftMotor(leftSpeed + modSpeed, forward);
}

void setRightMotor(int speed, bool forward) {
    analogWrite(MOTOR_PWM_A, speed);
    digitalWrite(MOTOR_DIRECTION_A, forward ? HIGH : LOW);
    rightSpeed = speed;
    rightForward = forward;
}

void modRightMotor(int modSpeed, bool forward) {
    setRightMotor(rightSpeed + modSpeed, forward);
}
