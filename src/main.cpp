//
// Created by Gjorg on 13/03/2024.
//

//#include <Arduino.h>
#include "SegmentDisplays.h"
#include "lineSensor.h"
#include "motorShield.h"
#include "lineTracing.h"

long countdown = 2;

int state = 0;

long startTime = 0;

bool flickering = true;

int getTime();

void setup() {

    TCCR2B = TCCR2B & (B11111000 | B00000111); // for PWM frequency of 30.64 Hz

    enableDisplays();
    enableSensor();
    enableMotors();
    // Countdown
//    Serial.begin(9600);
}

void loop() {
    // countdown state
    if (state == 0 ) {
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
                state = 1;
            }
        }
    // driving state
    } else if (state == 1) {
        if (drive()) {
            state = 2;
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
