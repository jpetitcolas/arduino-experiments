#include "MorseTranslator.h"

MorseTranslator morseTranslator(13, 200);

void setup()
{
    Serial.begin(9600);
    Serial.println("Serial link established!");
}

void loop()
{
    // If no serial link is available, do not go further.
    if (Serial.available() == -1) {
        return;
    }

    char c;
    while ((c = Serial.read()) > 0) {
        Serial.print(c);
        morseTranslator.emit(c);
    }
}