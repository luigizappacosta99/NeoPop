#include <cstdio>
#include <cmath>
#include <cstdlib>

#include "perlin.h"

double Noise(int i, int x, int y, int seed) {
  int primes[10][3] = {
  { 995615039, 600173719, 701464987 },
  { 831731269, 162318869, 136250887 },
  { 174329291, 946737083, 245679977 },
  { 362489573, 795918041, 350777237 },
  { 457025711, 880830799, 909678923 },
  { 787070341, 177340217, 593320781 },
  { 405493717, 291031019, 391950901 },
  { 458904767, 676625681, 424452397 },
  { 531736441, 939683957, 810651871 },
  { 997169939, 842027887, 423882827 }
};
  int n = x + y * seed;
  n = (n << 13) ^ n;
  int a = primes[i][0], b = primes[i][1], c = primes[i][2];
  int t = (n * (n * n * a + b) + c) & 0x7fffffff;
  return 1.0 - (double)(t)/1073741824.0;
}

double SmoothedNoise(int i, int x, int y, int seed) {
  double corners = (Noise(i, x-1, y-1, seed) + Noise(i, x+1, y-1, seed) +
                    Noise(i, x-1, y+1, seed) + Noise(i, x+1, y+1, seed)) / 16,
         sides = (Noise(i, x-1, y, seed) + Noise(i, x+1, y, seed) + Noise(i, x, y-1, seed) +
                  Noise(i, x, y+1, seed)) / 8,
         center = Noise(i, x, y, seed) / 4;
  return corners + sides + center;
}

double Interpolate(double a, double b, double x) {  // cosine interpolation
  double ft = x * 3.1415927,
         f = (1 - cos(ft)) * 0.5;
  return  a*(1-f) + b*f;
}

double InterpolatedNoise(int i, double x, double y, int seed) {
  int integer_X = x;
  double fractional_X = x - integer_X;
  int integer_Y = y;
  double fractional_Y = y - integer_Y;

  double v1 = SmoothedNoise(i, integer_X, integer_Y, seed),
         v2 = SmoothedNoise(i, integer_X + 1, integer_Y, seed),
         v3 = SmoothedNoise(i, integer_X, integer_Y + 1, seed),
         v4 = SmoothedNoise(i, integer_X + 1, integer_Y + 1, seed),
         i1 = Interpolate(v1, v2, fractional_X),
         i2 = Interpolate(v3, v4, fractional_X);
  return Interpolate(i1, i2, fractional_Y);
}

double ValueNoise_2D_perlin(double x, double y, int numOctaves, int seed) {
 
  double total = 0.0;
  double frequency = 0.02;
  double amplitude = 2.0;
  double amplitudeSum = 0.0;
  double persistence = 0.5;
  
  for (int i = 0; i < numOctaves; ++i) {
    int primeIndex = 0;
    int idx = (primeIndex + i) % 10;
    total += InterpolatedNoise(idx, x * frequency, y * frequency, seed) * amplitude;
    amplitudeSum += amplitude;
    amplitude *= persistence;
    frequency *= 2.0;
  }

  if (amplitudeSum == 0.0) return 0.0;
  return total / amplitudeSum;
}