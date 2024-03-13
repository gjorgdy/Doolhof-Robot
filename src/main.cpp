#include <Arduino.h>
#include "NewPing.h"
#include "SegmentDisplays.h"

long count = 0 * 1000;

int avg = 0;
int amount = 0;
int total = 0;
// motor shield
int dirA = 12;
int dirB = 13;
int pwmA = 3;
int pwmB = 11;

NewPing sonar(2, A5, 99);

void setup() {
    // Sensors
    pinMode(A0, INPUT_PULLUP);
    pinMode(A1, INPUT_PULLUP);
    pinMode(A2, INPUT_PULLUP);
    pinMode(A3, INPUT_PULLUP);
    pinMode(A4, INPUT_PULLUP);
    // Enable 7-segments
    enableDisplays();
    // Vroom
    pinMode(dirA, OUTPUT);
    pinMode(dirB, OUTPUT);
    pinMode(pwmA, OUTPUT);
    pinMode(pwmB, OUTPUT);
}

void loop()
{
    if (count > 10) {
        // count down using milliseconds
        writeDisplays((int) count / 1000);
        count -= 10;
    } else if (count == -1) {
        // print avg sonar distance to screens
        if (amount == 5) {
            avg = total / amount;
            amount = 0;
            total = 0;
        } else {
            total += (int) sonar.ping_cm();
            amount += 1;
        }
        writeDisplays(avg);
        // drive forward if no obstacle seen
        if (avg > 10) {
            analogWrite(pwmA, 150);
            analogWrite(pwmB, 150);
            digitalWrite(dirA, LOW);
            digitalWrite(dirB, HIGH);
        } else {
            digitalWrite(pwmA, LOW);
            digitalWrite(pwmB, LOW);
        }
    } else {
        count = -1;
        resetDisplays();
        delay(1000);
    }
}

