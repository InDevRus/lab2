#include <Arduino.h>

#include "components/Buzzer.h"
#include "components/Sensor.h"

#include "logic/NotesCalculator.h"

const auto buzzerPin = 12;

const auto echoPin = 8;
const auto triggerPin = 9;

Buzzer buzzer(buzzerPin);
Sensor sensor(echoPin, triggerPin);

void setup()
{
    Serial.begin(115200);
}

void loop()
{
    auto distance = sensor.senseDistance();
    auto noteFrequency = NotesCalculator::noteByDistance(distance);

    if (noteFrequency >= 0)
    {
        buzzer.toggleSound(noteFrequency);
    }
    else
    {
        buzzer.stopSound();
    }

    delay(200);
}