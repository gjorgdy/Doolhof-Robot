//
// Created by Gjorg on 24/03/2024.
//

#ifndef DOOLHOFROBOT_PATHSAVE_H
#define DOOLHOFROBOT_PATHSAVE_H

#include <Arduino.h>
#include <EEPROM.h>

void writePath();
String readPath();

void writeState(int);
int readState();

void addAction(char);

void resetEEPROM();

String optimize(String in);

#endif //DOOLHOFROBOT_PATHSAVE_H
