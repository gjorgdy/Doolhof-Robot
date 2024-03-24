//
// Created by Gjorg on 13/03/2024.
//

//#include <Arduino.h>
#include "SegmentDisplays.h"
#include "lineSensor.h"
#include "motorShield.h"
#include "lineTracing.h"
#include "pathSave.h"

long countdown = 2;

int state = 0; // set to -1 for debug

long startTime = 0;

bool flickering = true;

int getTime();
void setState(int);

void setup() {

    TCCR2B = TCCR2B & (B11111000 | B00000111); // for PWM frequency of 30.64 Hz

    enableDisplays();
    enableSensor();
    enableMotors();
    // Countdown
    if (state == -1) {
        Serial.begin(9600);
    }

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
    writeState(0);

}

void loop() {
    // scan the lineSensors
    scan();
    // debug state
    if (state == -1) {
        Serial.println(readPath());
        delay(1000);
    }
    // countdown state
    if (state == 0) {
        if (countdown != 0) {
            for (int i = 0 ; i < 250 ; i++) {
                writeDisplays((int) countdown);
            }
            Serial.println(countdown);
            if (sensor(W, W, W, W, W) || sensor(W, W, B, W, W)) {
                countdown -= 1;
            }
        } else {
            writeDisplays("st");
            startTime = (long) millis();
            goStraight();
            if (sensor(W, W, B, W, W) || sensor(W, W, B, W, W) || sensor(W, W, B, B, W) || sensor(W, B, B, B, W)) {
                setState(1);
            }
        }
    // driving state
    } else if (state == 1) {
        // returns true if finish is reached
        if (drive()) {
            setState(2);
        }
        writeDisplays(getTime());
    // finish state
    } else if (state == 2) {
        // DO NOT DRIVE
        stop();
        // flicker
        if (flickering) {
            int time = getTime();
            for (int i = 0; i < 6; i++) {
                if (i % 2 == 0) {
                    for (int j = 0; j < 125; j++) {
                        writeDisplays(time);
                    }
                } else {
                    emptyDisplays();
                    delay(500);
                }
            }
            flickering = false;
        } else {
            writeDisplays("fi");
        }

    }

}

int getTime() {
    long timeMs = (long) millis() - startTime;
    return (int) (timeMs / 1000);
}

void setState(int newState) {
    state = newState;
    writeState(newState);
}
