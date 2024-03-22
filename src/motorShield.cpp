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
    pinMode(dirA, OUTPUT);
    pinMode(dirB, OUTPUT);
    pinMode(pwmA, OUTPUT);
    pinMode(pwmB, OUTPUT);
}

void setLeftMotor(int speed, bool forward) {
    analogWrite(pwmB, speed);
    digitalWrite(dirB, forward ? HIGH : LOW);
    leftSpeed = speed;
    leftForward = forward;
}

void modLeftMotor(int modSpeed, bool forward) {
    setLeftMotor(leftSpeed + modSpeed, forward);
}

void setRightMotor(int speed, bool forward) {
    analogWrite(pwmA, speed);
    digitalWrite(dirA, forward ? LOW : HIGH);
    rightSpeed = speed;
    rightForward = forward;
}

void modRightMotor(int modSpeed, bool forward) {
    setRightMotor(rightSpeed + modSpeed, forward);
}
