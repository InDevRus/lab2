class Buzzer
{
private:
    int pin;

public:
    Buzzer(int pin);
    ~Buzzer();

    void toggleSound(int frequency);
    void stopSound();
};

Buzzer::Buzzer(int pin)
{
    pinMode(pin, OUTPUT);
    this->pin = pin;
}

Buzzer::~Buzzer()
{
}

void Buzzer::toggleSound(int frequency)
{
    tone(pin, frequency);
}

void Buzzer::stopSound()
{
    noTone(pin);
}