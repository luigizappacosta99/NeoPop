#include <cstdint>
#include <algorithm>
#include <cmath>

#include "png.h"

HSV rgbToHsv(uint8_t r, uint8_t g, uint8_t b) {
    float rf = r / 255.f, gf = g / 255.f, bf = b / 255.f;
    float cmax = std::max({rf, gf, bf});
    float cmin = std::min({rf, gf, bf});
    float delta = cmax - cmin;

    HSV out{};
    out.v = cmax;
    out.s = (cmax > 0.f) ? delta / cmax : 0.f;

    if (delta < 1e-6f) { out.h = 0.f; return out; }

    if      (cmax == rf) out.h = 60.f * fmodf((gf - bf) / delta, 6.f);
    else if (cmax == gf) out.h = 60.f * ((bf - rf) / delta + 2.f);
    else                 out.h = 60.f * ((rf - gf) / delta + 4.f);

    if (out.h < 0.f) out.h += 360.f;
    return out;
}

float getFertilityValue(uint8_t r, uint8_t g, uint8_t b) {
    HSV hsv = rgbToHsv(r, g, b);

    // Skip low-saturation or very dark pixels (borders, background, legend box)
    if (hsv.s < 0.5f || hsv.v < 0.15f) return -1.f;

    float h = hsv.h;
    float v = hsv.v;

    // Red: hue 0–20° (wraps near 360°), high value
    if (h < 20.f || h >= 340.f)
        return 0.10f;   // fertility 0–20, very poor

    // Orange: hue 20–55°
    if (h < 55.f)
        return 0.30f;   // fertility 20–40, poor

    // Yellow: hue 55–65°  (pure yellow sits at exactly 60°)
    if (h < 65.f)
        return 0.50f;   // fertility 40–60, moderate

    // Light green: hue 65–90°, brighter (v > 0.5)
    // These are the yellow-greens: h≈66–87, v≈0.63–0.75
    if (h < 90.f && v > 0.5f)
        return 0.70f;   // fertility 60–80, good

    // Dark green: hue 90–125°, darker (v ≤ 0.5)
    // h≈90–120, v≈0.31–0.50
    if (h < 125.f)
        return 0.90f;   // fertility 80–100, very good

    return -1.f;
}

// Process a full image. pixels = raw RGB (or RGBA) bytes.
// channels = 3 or 4. outMap must be pre-allocated to width*height floats.
void extractFertilityMap(
    const uint8_t* pixels,
    int width, int height,
    int stride, int channels,
    float* outMap)
{
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            const uint8_t* p = pixels + y * stride + x * channels;
            outMap[y * width + x] = getFertilityValue(p[0], p[1], p[2]);
        }
    }
}