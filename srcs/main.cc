#include <iostream>
#include <fstream>
#include "../include/perlin.h"
#include "../include/map.h"
#include "../include/pixel.h"
#include "../include/tribe.h"

enum class biomes {
    FOREST,
    DESERT,
    PLAINS,
    MOUNTAIN,
    OCEAN
};

int main(int argc, char const *argv[])
{
    //generate a random 50x50 map and cout fertility
    int map_width = 50;
    int map_height = 50;
    map m(map_width, map_height);
    m.generateFromPerlinNoise();
    //generate a tribe and plot it on the map
    tribe t(2, 2, 100);
    //print altitude in a txt file
    std::ofstream outfile("altitude.txt");
    for (int i = 0; i < map_height; i++) {
        for (int j = 0; j < map_width; j++) {
            outfile << m.getPixel(j, i)->getHeight() << " ";
        }
        outfile << std::endl;
    }
    outfile.close();
    //print fertility in a txt file
    std::ofstream fertility_file("fertility.txt");
    for (int i = 0; i < map_height; i++) {
        for (int j = 0; j < map_width; j++) {
            fertility_file << m.getPixel(j, i)->getFertility() << " ";
        }
        fertility_file << std::endl;
    }
    fertility_file.close();
    //print tribe info
    std::cout << "Tribe position: (" << t.getX() << ", " << t.getY() << ")" << std::endl;
    std::cout << "Tribe population: " << t.getPopulation() << std::endl;
    return 0;
}
