#ifndef SERIAL_H_INCLUDED
#define SERIAL_H_INCLUDED

#include <stdio.h>
#include <string.h>
#include <SDL/SDL.h>
FILE *arduinoIN;
FILE *arduinoOUT;

int GetJoystick(int * x,int * y);
int SerialOpen();
int SerialRead(char buffer[]);
void SerialWrite(char ch[], char len);
void SerialClose();

#endif // SERIAL_H_INCLUDED
