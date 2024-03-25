//
// Created by Gjorg on 13/03/2024.
//

#include "pins.h"

void enableDisplays();

void selectDisplay(int display);
void writeDisplays(int number);
void writeDisplays(const String& string);
void writeDisplay(int digit);
void writeDisplay(char character);

void resetDisplays();
void emptyDisplays();

