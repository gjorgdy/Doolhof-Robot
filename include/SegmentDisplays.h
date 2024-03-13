//
// Created by Gjorg on 13/03/2024.
//

#include <Arduino.h>

// 7-segment
static int segA = 10;
static int segB = 9;
static int segC = 8;
static int segD = 7;
static int segE = 6;
static int segF = 5;
static int segG = 4;

static int gnd0 = 0;
static int gnd1 = 1;

void enableDisplays();
void resetDisplays();
void writeDisplays(int value);
void selectDisplay(int display);
void writeDisplay(int digit);

