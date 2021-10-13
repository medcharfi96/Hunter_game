#include "libserialport.h" 
#include "arduino-serial-lib.h"

FILE *arduinoIN;
FILE *arduinoOUT;

int GetJoystick(int * x,int * y)
{
    int len;
    int read=0;
    char buffer [100]= {0};

    while((len=SerialRead(buffer))>0)
    {
        buffer[11]=0;
        sscanf(buffer,"X%dY%d",x,y);
        SDL_Delay(20);
        read=1;
    }
   return read;
}



int SerialOpen()
{
    arduinoIN = fopen("/dev/ttyACM1","r");
    arduinoOUT = fopen("/dev/ttyACM1","w");
    return arduinoIN!=NULL && arduinoOUT!=NULL;
}

int SerialRead(char buffer[])
{
    int i=0,len;
    if(arduinoIN)
    {
        len=fgetc(arduinoIN);
        while(i<len)
        {
            while((buffer[i]=fgetc(arduinoIN))!=EOF)
            {
                i++;
            }
        }
    }
    return i;
}


void SerialWrite(char ch[], char len)
{
    if(arduinoOUT)
    {
        fwrite(&len,1,1,arduinoOUT);
        fwrite(ch,len,1,arduinoOUT);
        fflush(arduinoOUT);
    }
}

void SerialClose()
{
    fclose(arduinoIN);
    fclose(arduinoOUT);
    arduinoIN=NULL;
    arduinoOUT=NULL;
}

