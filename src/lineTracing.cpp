//
// Created by Gjorg on 22/03/2024.
//

#include "NewPing.h"
#include "lineTracing.h"

int averagecount = 0;
int averagearray[5][5];

int avg = 0;
int amount = 0;
int total = 0;

static int finishCount = 0;

int objectstate = 0;
unsigned long objecttime = 0;
int turnstate = 0;
unsigned long turntime = 0;
int blackstate = 0;
unsigned long blacktime = 0;

NewPing sonar(2, A5, 99);

boolean drive() {

    long dist = (long) sonar.ping_cm();

    averagearray[averagecount][0] = digitalRead(sen4);
    averagearray[averagecount][0] = digitalRead(sen3);
    averagearray[averagecount][0] = digitalRead(sen2);
    averagearray[averagecount][0] = digitalRead(sen1);
    averagearray[averagecount][0] = digitalRead(sen0);
    averagecount++;

    if (averagecount==5) {
        averagecount = 0;
    }

    if (((long) millis()) - 700 > objecttime && (dist > 10 || dist == 0) ) {
        objectstate = 0;
        Serial.println("state naar 0");
    }
    if (((long) millis()) - 200 > blacktime) {
        blackstate = 0;
        Serial.println("state naar 0");
    }
    if (((long) millis()) - 100 > turntime) {
        turnstate = 0;
        Serial.println("state naar 0");
    } else return false;

    if ((dist < 7 && dist != 0) || objectstate == 1 ) {
        if (objectstate == 0 && millis() - 1000 > objecttime) {
            objecttime = millis();
            objectstate = 1;
        }
        Serial.println("fullTurn");
        fullTurn();

    }  else if (sensor(W, W, B, B, B) || sensor(W, W, W, B, B) || sensor(W, W, W, W, B) || sensor(W, B, B, B, B) ) {
        if (turnstate == 0) {
            turntime = millis();
            turnstate = 1;
        }
        Serial.println("turnRight");
        turnRight();
    } else if (sensor(B, B, B, W, W) || sensor(B, B, W, W, W) || sensor(B, B, B, B, W) || sensor(B, W, W, W, W) ) {
        if (turnstate == 0) {
            turntime = millis();
            turnstate = 1;
        }
        Serial.println("turnLeft");
        turnLeft();
    } else if (sensor(B, B, B, B, B) || blackstate == 1) {
        if (blackstate == 0) {
            blacktime = millis();
            blackstate = 1;
        }
        Serial.println("win? " + String(finishCount));
        goStraight();
//        if (finishCount == 0) {
//        fullOuterTurn();
//        } else
        if (finishCount < 16) {
//            modTurnBlack();
            finishCount += 1;
            return false;
        } else {
            return true;
        }
    } else if (sensor(W, W, B, W, W)) {
        // drive code
        Serial.println("In middle");
        if (lastSensor(B, B, B, B, B)) {
            fullTurn();
        } else {
            goStraight();
        }
    } else if (sensor(W, W, B, B, W) || sensor(W, W, W, B, W)) {
        Serial.println("slightRight");
        slightRight();
    } else if (sensor(W, B, B, W, W) || sensor(W, B, W, W, W)) {
        Serial.println("slightLeft");
        slightLeft();
    } else if (sensor(W, W, W, W, W) || (dist != 0 && dist < 10)) {
        Serial.println("???");
        fullTurn();
    }
    finishCount = 0;
    return false;
}
