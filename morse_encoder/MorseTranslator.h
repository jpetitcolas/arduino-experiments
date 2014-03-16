#ifndef MORSE_TRANSLATOR_H
#define MORSE_TRANSLATOR_H

#include "Arduino.h"

class MorseTranslator
{
    public:
        MorseTranslator(byte pin, unsigned int timeUnit);
        void emit(char);

    private:
    	String getSignalForChar(char);
    	void dot();
        void dash();
        void endLetter();
        void space();

        byte _pin;
        unsigned int _timeUnit;
};

#endif