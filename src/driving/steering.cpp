//
// Created by Gjorg on 22/03/2024.
//

bool leftLeaning = true;

#include "steering.h"

void goStraight() {
    setLeftMotor(baseSpeed, true);
    setRightMotor(baseSpeed, true);
}

void slightRight() {
    setLeftMotor(baseSpeed + slightSteerDelta, true);
    setRightMotor(baseSpeed - slightSteerDelta, true);
}

void slightLeft() {
    setLeftMotor(baseSpeed - slightSteerDelta, true);
    setRightMotor(baseSpeed + slightSteerDelta, true);
}

void turnRight() {
    if (leftLeaning) {
        goStraight();
    } else {
        setLeftMotor(baseSpeed + steerDelta, true);
        setRightMotor(baseSpeed - steerDelta, false);
    }
}

void turnLeft() {
    if (leftLeaning) {
        setLeftMotor(baseSpeed - steerDelta, false);
        setRightMotor(baseSpeed + steerDelta, true);
    } else {
        goStraight();
    }
}

void fullOuterTurn() {
    if (leftLeaning) {
        setLeftMotor(0, false);
        setRightMotor(baseSpeed, true);
    } else {
        setLeftMotor(baseSpeed, true);
        setRightMotor(0, false);
    }
}

void fullTurn() {
    if (leftLeaning) {
        setLeftMotor(baseSpeed, true);
        setRightMotor(baseSpeed, false);
    } else {
        setLeftMotor(baseSpeed, false);
        setRightMotor(baseSpeed, true);
    }
}

void stop() {
    setLeftMotor(0, true);
    setRightMotor(0, true);
}