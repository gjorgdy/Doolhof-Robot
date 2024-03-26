//
// Created by Gjorg on 22/03/2024.
//

#include "NewPing.h"
#include "lineTracing.h"
#include "pathSave.h"

int finishCount = 0;
unsigned long blockTill = 0;
unsigned long blockTillAtLeast = 0;

bool left;
bool right;

void block(int minMs, int maxMs);
void unblock();
bool isBlocked();

NewPing sonar(SONAR_TRIG, SONAR_ECHO, 20);

bool drive() {
    if (left) {
        block(300, 1000);
        turnLeft();
        left = false;
        return false;
    }
    if (sensor(B, B, B, B, B)) {
        if (finishCount < (baseSpeed/1)) {
            finishCount += 1;
        } else {
            return true;
        }
        // count amount of ticks on finish
    } else {
        finishCount = 0;
    }
    // if robot is doing a blocking action
    if (millis() > blockTill || (isOnLine() && millis() > blockTillAtLeast)) {
        unblock();
    } else if (isBlocked()) return false;
    // get distance of ping sonar
    long dist = (long) sonar.ping_cm();
    // if ping sensor detects object or sees no line
    if ((dist < 10 && dist != 0 )) {
        block(300, 1000);
        fullTurn();
    } else if (sensor(W, W, W, W, W)) {
        fullTurn();
        if (isLeftLeaning()) {
            addAction('R');
        } else {
            addAction('L');
        }

        if (whiteCount < 1000) {
            finishCount = 0;
            whiteCount += 1;
            return false;
        } else {
            slightLeft();
            block(100, 2000);
        }
    // if sensors see a turn to the right
    } else if (sensor(W, W, B, B, B) || sensor(W, B, B, B, B)) {
        if (!isLeftLeaning()) {
            block(100, 500);
            addAction('R');
        } else {
            addAction('S');
        }
        turnRight();
    // if sensors see a turn to the left
    } else if (sensor(B, B, B, B, W) || sensor(B, B, B, W, W)) {
        block(500);
        turnLeft();
    // if sensors see only black
    } else if (sensor(B, B, B, B, B)) {
        block(200, 700);
        fullOuterTurn();
        // count amount of ticks on finish
        if (finishCount < 15) {
            finishCount += 1;
            return false;
        } else {
            return true;
        }
    // if sensors see a line in the middle
    } else if (sensor(W, W, B, W, W)) {
        goStraight();
    // if sensors see the line on its right
    } else if (sensor(W, W, B, B, W) || sensor(W, W, W, B, W) || sensor(W, W, W, B, B) || sensor(W, B, B, B, B)) {
        slightRight();
    // if sensors see the line on its left
    } else if (sensor(W, B, B, W, W) || sensor(W, B, W, W, W) || sensor(B, W, W, W, W)) {
        slightLeft();
    }
    finishCount = 0;
    return false;
}

bool isOnLine() {
    return sensor(W, W, B, W, W)
//    || sensor(W, B, W, W, W) || sensor(W, W, W, B, W) || sensor(W, W, B, B, W) || sensor(W, B, B, W, W); || sensor(W, B, B, W, W) || sensor(W, W, B, B, W)
    ;
}

void block(int minMs, int maxMs) {
    blockTillAtLeast = millis() + minMs;
    blockTill = millis() + maxMs;
}

void unblock() {
    blockTill = 0;
    blockTillAtLeast = 0;
}

bool isBlocked() {
    return blockTill != 0 && blockTillAtLeast != 0;
}