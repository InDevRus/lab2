#include <Arduino.h>

#include "components/Buzzer.h"
#include "components/Sensor.h"

#include "logic/NotesCalculator.h"

const auto buzzerPin = 16;

const auto echoPin = 8;
const auto triggerPin = 9;

Buzzer buzzer(buzzerPin);
Sensor sensor(echoPin, triggerPin);

void setup()
{
}

void loop()
{
    auto distance = sensor.senseDistance();
    auto *noteFrequencyPointer = NotesCalculator::noteByDistance(distance);

    if (noteFrequencyPointer != nullptr)
    {
        buzzer.toggleSound(*noteFrequencyPointer);
    }
    else
    {
        buzzer.stopSound();
    }

    delay(200);
}