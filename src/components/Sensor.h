#include <Arduino.h>

class Sensor
{
private:
    const float soundSpeedMeterPerSecond = 340.0;
    const float soundSpeedCmPerSecond = soundSpeedMeterPerSecond / 10000.0;

    int echoPin, triggerPin;

public:
    Sensor(int echoPin, int triggerPin);
    ~Sensor();

    float senseDistance();
};

Sensor::Sensor(int echoPin, int triggerPin)
{
    pinMode(echoPin, INPUT);
    pinMode(triggerPin, OUTPUT);

    this->echoPin = echoPin;
    this->triggerPin = triggerPin;

    digitalWrite(triggerPin, LOW);
}

Sensor::~Sensor()
{
}

float Sensor::senseDistance()
{
    digitalWrite(triggerPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(triggerPin, LOW);

    auto duration = pulseIn(echoPin, HIGH);
    return duration * soundSpeedCmPerSecond / 2.0;
}