//
// Created by Gjorg on 22/03/2024.
//

#ifndef DOOLHOF_ROBOT_STEERING_H
#define DOOLHOF_ROBOT_STEERING_H

#include "motorShield.h"
bool isLeftLeaning();

void goStraight();

void slightLeft();
void slightRight();

void turnLeft();
void tightTurnLeft();
void turnRight();

void fullTurn();
void fullOuterTurn();

void stop();
void reverse();

#endif //DOOLHOF_ROBOT_STEERING_H
