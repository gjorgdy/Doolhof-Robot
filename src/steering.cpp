//
// Created by Gjorg on 22/03/2024.
//

#define leftLeaning true

#include "steering.h"

void goStraight() {
    setLeftMotor(baseSpeed, true);
    setRightMotor(baseSpeed, true);
}

void slightRight() {
    setLeftMotor(baseSpeed - slightSteerDelta, true);
    setRightMotor(baseSpeed + slightSteerDelta, true);
}

void slightLeft() {
    setLeftMotor(baseSpeed + slightSteerDelta, true);
    setRightMotor(baseSpeed - slightSteerDelta, true);
}

void turnRight() {
    setLeftMotor(baseSpeed + steerDelta, true); // leftleaning : true
    setRightMotor(baseSpeed - steerDelta, leftLeaning); // leftleaning : true
}

void turnLeft() {
    setLeftMotor(baseSpeed - steerDelta, !leftLeaning); // leftleaning : false
    setRightMotor(baseSpeed + steerDelta, true); // leftleaning : true
}

void turnBlack() {
    if (leftLeaning) {
        setLeftMotor(0, false);
        setRightMotor(baseSpeed, true);
    } else {
        setLeftMotor(baseSpeed, true);
        setRightMotor(0, false);
    }
}

void modTurnBlack() {
    if (leftLeaning) {
        modRightMotor(-1 * slightSteerDelta, true);
    } else {
        modLeftMotor(-1 * slightSteerDelta, true);
    }
}

void turn() {
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