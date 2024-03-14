#include "Arduino.h"
#include "Register.h"

Register::Register(int dat1, int verrou, int clk, int reg)
{
    nbrReg = reg;
    dataPin = dat1;
    latchPin = verrou;
    clockPin = clk;
    OutResol(reg);
}

void Register::SetRegPin()
{
    pinMode(dataPin, OUTPUT);
    pinMode(latchPin, OUTPUT);
    pinMode(clockPin, OUTPUT);
}

void Register::initOut()
{
    byte sortie = ToByte(outReg);
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, sortie); 
    digitalWrite(latchPin, HIGH);
}

void Register::Set(int pinNum)
{
    byte sortie = selectOut(pinNum, 'S');
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, sortie); 
    digitalWrite(latchPin, HIGH);
}

void Register::Reset(int pinNum)
{
    byte sortie = selectOut(pinNum, 'R');
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, sortie); 
    digitalWrite(latchPin, HIGH);
}

byte Register::ToByte(String str) 
{
    byte byteValue = 0;
    for (int i = str.length() - 1; i >= 0; i--) {
        char c = str.charAt(i);
        byte bit;
        if (c == '0')
        { 
            bit = 0; 
        } 
        else if (c == '1') 
        { 
            bit = 1; 
        } 
        else
        {
            return 0;
        }
        byteValue = (byteValue << 1) | bit;
    }
    return byteValue;
}

byte Register::selectOut(int num, char etat)
{
    if ((num >= 0) || (num <= 7))
    {
        if (etat == 'S')
        { 
            outReg[7-num] = '1'; 
        }
        if (etat == 'R')
        { 
            outReg[7-num] = '0';
        }
        return ToByte(outReg);
    }
    else 
    {
        return ToByte(outReg);
    }
}

void Register::OutResol(int num)
{
    if (num == 1)
    {
        outReg = "00000000";
    }
}