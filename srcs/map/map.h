#ifndef MAP_H
#define MAP_H

#include <vector>
#include "pixel.h"

class map
{
private:
    std::vector<std::vector<pixel*>> grid;
    int width;
    int height;

public:
    map(int width, int height);
    ~map();

    //generate from perlin noise
    void generateFromPerlinNoise();

    pixel* getPixel(int x, int y);
    void setPixel(int x, int y, pixel* p);

    //prints
    //void printMap();
    void printHeight(std::ostream& os);
    void printFertility(std::ostream& os);
    void printUsage(std::ostream& os);
    void printAnimalPopulation(std::ostream& os);
    void printMegafaunaPopulation(std::ostream& os);
};

#endif