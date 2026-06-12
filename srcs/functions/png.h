#ifndef PNG_H
#define PNG_H

#include <cstdint>

struct HSV { float h, s, v; };

void extractFertilityMap(
    const uint8_t* pixels,
    int width, int height,
    int stride, int channels,
    float* outMap);

#endif