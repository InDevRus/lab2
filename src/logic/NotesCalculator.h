#include <Arduino.h>

namespace NotesCalculator
{

/**
 * Считает частоту звучания по расстоянию до ультразвукового дальнометра.
 * 
 * Предел для наличия звука будем счиатать равным 15 см.
 * Чем ближе объект до дальнометра, тем выше звук.
 * Диапазон частот: 31 Гц - 3951 Гц.
 * 
 * @param distance Расстояние до дальнометра (в сантиметрах)
 * @return Указатель на вычисленную частоту, либо <code>nullptr</code>,
 * если расстояние слишком велико
 */
unsigned int *noteByDistance(double distance)
{
    auto scale = 15.0;

    if (distance > scale)
        return nullptr;

    auto upperBound = 3951;
    auto lowerBound = 31;

    auto result = (unsigned int) round(upperBound - ((upperBound - lowerBound) * distance / scale));
    auto *pointer = &result;
    return pointer;
}
} // namespace NotesCalculator