//
// Created by Gjorg on 22/03/2024.
//

#include "NewPing.h"
#include "lineTracing.h"

static int finishCount = 0;

unsigned long blockTill = 0;

bool isOnLine();
void block(int ms);
void unblock();
bool isBlocked();

NewPing sonar(2, A5, 99);


boolean drive() {
    // if robot is doing a blocking action
    if (isBlocked() && (millis() > blockTill || isOnLine())) {
        unblock();
    } else return false;

    // get distance of ping sonar
    long dist = (long) sonar.ping_cm();

    // if ping sensor detects object or sees no line
    if ((dist < 7 && dist != 0 )|| sensor(W, W, W, W, W)) {
        block(500);
        fullTurn();
    // if sensors see a turn to the right
    } else if (sensor(W, W, B, B, B) || sensor(W, W, W, B, B) || sensor(W, W, W, W, B) || sensor(W, B, B, B, B) ) {
        block(500);
        turnRight();
    // if sensors see a turn to the left
    } else if (sensor(B, B, B, W, W) || sensor(B, B, W, W, W) || sensor(B, B, B, B, W) || sensor(B, W, W, W, W) ) {
        block(500);
        turnLeft();
    // if sensors see only black
    } else if (sensor(B, B, B, B, B)) {
        block(500);
        fullOuterTurn();

        if (finishCount < 15) {
            finishCount += 1;
            return false;
        } else {
            return true;
        }
    // if sensors see a line in the middle
    } else if (sensor(W, W, B, W, W)) {
        goStraight();
    // if sensors see the line on its left
    } else if (sensor(W, W, B, B, W) || sensor(W, W, W, B, W)) {
        slightRight();
    // if sensors see the line on its right
    } else if (sensor(W, B, B, W, W) || sensor(W, B, W, W, W)) {
        slightLeft();
    }
    finishCount = 0;
    return false;
}

bool isOnLine() {
    return sensor(W, W, B, W, W) || sensor(W, B, B, W, W) || sensor(W, W, B, B, W);
}

void block(int ms) {
    blockTill = millis() + ms;
}

void unblock() {
    blockTill = 0;
}

bool isBlocked() {
    return blockTill != 0;
}