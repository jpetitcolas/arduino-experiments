struct dictionnaryEntry {
    char character;
    String signal;
};

dictionnaryEntry dictionnary[36] = {
	{ 'a', ".-" },
  	{ 'b', "-..." },
  	{ 'c', "-.-." },
  	{ 'd', "-.." },
  	{ 'e', "." },
  	{ 'f', "..-." },
  	{ 'g', "--." },
  	{ 'h', "...." },
  	{ 'i', ".." },
  	{ 'j', ".---" },
  	{ 'k', "-.-" },
  	{ 'l', ".-.." },
  	{ 'm', "--" },
  	{ 'n', "-." },
  	{ 'o', "---" },
  	{ 'p', ".--." },
  	{ 'q', "--.-" },
  	{ 'r', ".-." },
  	{ 's', "..." },
  	{ 't', "-" },
  	{ 'u', "..-" },
  	{ 'v', "...-" },
  	{ 'w', ".--" },
  	{ 'x', "-..-" },
  	{ 'y', "-.--" },
  	{ 'z', "--.." },
  	{ '0', "-----" },
  	{ '1', ".----" },
  	{ '2', "..---" },
  	{ '3', "...--" },
  	{ '4', "....-" },
  	{ '5', "....." },
  	{ '6', "-...." },
  	{ '7', "--..." },
  	{ '8', "---.." },
  	{ '9', "----." }
};

MorseTranslator::MorseTranslator(byte pin, unsigned int timeUnit)
{
    pinMode(pin, OUTPUT);
    _pin = pin;
    _timeUnit = timeUnit;
}

void MorseTranslator::dot()
{
    digitalWrite(_pin, HIGH);
    delay(_timeUnit);
    digitalWrite(_pin, LOW);
    delay(_timeUnit);
}

void MorseTranslator::dash()
{
    digitalWrite(_pin, HIGH);
    delay(3 * _timeUnit);
    digitalWrite(_pin, LOW);
    delay(_timeUnit);
}

void MorseTranslator::endLetter()
{
    delay(3 * _timeUnit);
}

void MorseTranslator::space()
{
    delay(7 * _timeUnit);
}

String MorseTranslator::getSignalForChar(char c)
{
    byte i;
    for (i = 0 ; i < 36 ; i++) {
        if (dictionnary[i].character == c) {
            return dictionnary[i].signal;
        }
    }

    // If no matching character, consider it is a space.
    return " ";
}

void MorseTranslator::emit(char c)
{
    String signal = getSignalForChar(c);

    byte i;
    char signalLength = signal.length();
    for (i = 0 ; i < signalLength ; i++) {
        switch (signal.charAt(i)) {
            case '.':
                dot();
                break;

            case '-':
                dash();
                break;

            case ' ':
                space();
                return;
        }
    }

    endLetter();
}
