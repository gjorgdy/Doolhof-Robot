//
// Created by Gjorg on 22/03/2024.
//

#define leftLeaning false

#include "steering.h"

bool leftLeaning = true;
bool gostraight = false;

void goStraight() {
    setLeftMotor(baseSpeed, true);
    setRightMotor(baseSpeed, true);
}

void slightRight() {
    setLeftMotor(baseSpeed - slightSteerDelta, true);
    setRightMotor(baseSpeed + slightSteerDelta, true);
}

void slighterRight() {
    setLeftMotor(baseSpeed - slighterSteerDelta, true);
    setRightMotor(baseSpeed + slighterSteerDelta, true);
}

void slightLeft() {
    setLeftMotor(baseSpeed + slightSteerDelta, true);
    setRightMotor(baseSpeed - slightSteerDelta, true);
}

void slighterLeft() {
    setLeftMotor(baseSpeed + slighterSteerDelta, true);
    setRightMotor(baseSpeed - slighterSteerDelta, true);
}

void turnRight() {
    if (gostraight) {
        goStraight();
        gostraight = false;
        return;
    }
    slightRight();
//    setLeftMotor(baseSpeed, true); // leftleaning : true
//    setRightMotor(baseSpeed, false); // leftleaning : true
//    setLeftMotor(baseSpeed + steerDelta, true); // leftleaning : true
//    setRightMotor(baseSpeed - steerDelta, leftLeaning); // leftleaning : true
}

void turnLeft() {
    if (gostraight) {
        goStraight();
        gostraight = false;
        return;
    }
//    setLeftMotor(baseSpeed, false); // leftleaning : true
//    setRightMotor(baseSpeed, true); // leftleaning : true
    setLeftMotor(baseSpeed - steerDelta, !leftLeaning); // leftleaning : false
    setRightMotor(baseSpeed + steerDelta, true); // leftleaning : true
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
    if (leftLeaning || lastSensor(B, B, B, W, W)) {
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