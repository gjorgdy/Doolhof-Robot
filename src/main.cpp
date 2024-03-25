//
// Created by Gjorg on 13/03/2024.
//

//#include <Arduino.h>
#include "SegmentDisplays.h"
#include "lineSensor.h"
#include "motorShield.h"
#include "lineTracing.h"
#include "pathSave.h"

long countdownLen = 2;

int state = 0; // set to -1 for debug
long stateTime = 0; // time spent in current state
int drivingTime = 0;
boolean saved = false;

long getTime();
int getTimeSec();
void nextState();

void setup() {

    TCCR2B = TCCR2B & (B11111000 | B00000111); // for PWM frequency of 30.64 Hz

    enableDisplays();
    enableSensor();
    enableMotors();

    // reset EEPROM if restarted in state 0
    if (readState() == 0) {
        resetEEPROM();
        for (int i = 0; i < 6; i++) {
            if (i % 2 == 0) {
                for (int j = 0; j < 50; j++) {
                    writeDisplays("re");
                }
            } else {
                emptyDisplays();
                delay(200);
            }
        }
    }
    // Debug logic
    if (state == -1) {
        Serial.begin(9600);
    } else {
        stateTime = millis();
        writeState(0);
    }
}

void loop() {
    // scan the lineSensors
    scan();
    // debug state
    if (state == -1) {
//        writePath();
        Serial.println(readPath());
        delay(1000);
    }
    // countdown state
    if (state == 0) {
        int countdown = countdownLen - getTimeSec();
        // debug
        Serial.println(countdown);
        // show number on 7-segment
        if (countdown > 0) {
            writeDisplays((int) countdown);
        // go to next state on 0
        } else {
            nextState();
        }
    // starting state
    } else if (state == 1) {
        // show 'st'
        writeDisplays("st");
        // don't run the rest of the code for first second or if not on full white
        if (getTime() > 1000 && (sensor(W, W, W, W, W) || sensor(W, W, B, W, W))) {
            nextState();
        }
    // ready state
    } else if (state == 2) {
        resetDisplays();
        // drive forward
        if (sensor(W, W, W, W, W)) {
            goStraight();
        }
        // go to next state when a line is visible
        if (sensor(W, W, B, W, W) || sensor(W, B, B, W, W) || sensor(W, W, B, B, W) || sensor(W, B, B, B, W)) {
            stateTime = (long) millis();
            nextState();
        }
    // driving state
    } else if (state == 3) {
        // returns true if finish is reached
        if (drive()) {
            drivingTime = getTimeSec();
            nextState();
        }
        writeDisplays(getTimeSec());
    // result state
    } else if (state == 4) {
        // DO NOT DRIVE
        stop();
        // flicker time
        for (int i = 0; i < 6; i++) {
            if (i % 2 == 0) {
                for (int j = 0; j < 125; j++) {
                    writeDisplays(drivingTime);
                }
            } else {
                emptyDisplays();
                delay(500);
            }
        }
        nextState();
    // finished state
    } else if (state == 5) {
        writeDisplays("fi");
        // dance?
        // save path to EEPROM
        if (!saved) {
            writePath();
            saved = true;
        }
    }

}

long getTime() {
    return (long) millis() - stateTime;
}

int getTimeSec() {
    return (int) (getTime() / 1000);
}

void nextState() {
    state++;
    stateTime = millis();
    writeState(state);
}
