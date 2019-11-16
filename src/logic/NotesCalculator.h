#include <Arduino.h>

namespace NotesCalculator
{

/**
 * Считает частоту звучания по расстоянию до ультразвукового дальнометра.
 * 
 * Предел для наличия звука будем счиатать равным 25 см.
 * Чем ближе объект до дальнометра, тем выше звук.
 * Диапазон частот: 31 Гц - 3951 Гц.
 * 
 * @param distance Расстояние до дальнометра (в сантиметрах)
 * @return Вычисленную частоту, либо -1, если расстояние превышает 25 см.
 */
int noteByDistance(double distance)
{
    auto upperDistanceBound = 25.0;
    auto lowerDistanceBound = 0.0;
    auto distanceSpan = upperDistanceBound - lowerDistanceBound;

    auto upperFrequencyBound = 3951.0;
    auto lowerFrequencyBound = 31.0;
    auto frequencySpan = upperFrequencyBound - lowerFrequencyBound;

    if (distance > upperDistanceBound)
        return -1;

    return (int)round((upperDistanceBound - distance) / distanceSpan * frequencySpan + lowerFrequencyBound);
}
} // namespace NotesCalculator