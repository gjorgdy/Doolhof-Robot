//
// Created by Gjorg on 13/03/2024.
//

#include <Arduino.h>

// 7-segment
#define segA 10
#define segB 9
#define segC 8
#define segD 7
#define segE 6
#define segF 5
#define segG 4

#define gnd0 0
#define gnd1 1

void enableDisplays();

void selectDisplay(int display);
void writeDisplays(int number);
void writeDisplays(const String& string);
void writeDisplay(int digit);
void writeDisplay(char character);

void resetDisplays();
void emptyDisplays();

