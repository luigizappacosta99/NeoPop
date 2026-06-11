#include <iostream>
#include <ctime>
#include "../include/map.h"
#include "../include/perlin.h"

int seed = std::time(nullptr);

map::map(int width, int height) : width(width), height(height) {
    grid.resize(height);
    for (int i = 0; i < height; i++) {
        grid[i].resize(width, nullptr);
    }
    //call perlin noise generator to fill the map
    generateFromPerlinNoise();
}

map::~map() {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            delete grid[i][j];
        }
    }
}

void map::generateFromPerlinNoise() {
    //generate height from perlin noise and fill the map
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int h = ValueNoise_2D_perlin(j, i, 18, 0.5, seed) * 6000 + 100;
            bool is_passable = h < 800;
            double fertility = ValueNoise_2D_perlin(j+100, i, 7, 0.5, seed+23);
            //TO STUDY: FERTILITY
            //function that goies from 0 to 1, -1 for unpassable terrain
            //double fertility = humidity * std::abs(25-temperature) / (0.001*height*height);
            //if(h<0){fertility = -1.0f;}
            pixel* p = new pixel(j, i, h, fertility);
            grid[i][j] = p;
        }
    }
}

//void map::generateFromPNG() {
//
//}

pixel* map::getPixel(int x, int y) {
    if (x >= 0 && x < width && y >= 0 && y < height) {
        return grid[y][x];
    }
    return nullptr;
}

void map::setPixel(int x, int y, pixel* p) {
    if (x >= 0 && x < width && y >= 0 && y < height) {
        grid[y][x] = p;
    }
}

//prints

void map::printHeight(std::ostream& os) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (grid[i][j]) {
                os << grid[i][j]->getHeight() << " ";
            } else {
                os << "N/A ";
            }
        }
        os << '\n';
    }
}

void map::printFertility(std::ostream& os) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (grid[i][j]) {
                os << grid[i][j]->getFertility() << " ";
            } else {
                os << "N/A ";
            }
        }
        os << '\n';
    }
}

void map::printUsage(std::ostream& os) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (grid[i][j]) {
                os << grid[i][j]->getUsage() << " ";
            } else {
                os << "N/A ";
            }
        }
        os << '\n';
    }
}

void map::printAnimalPopulation(std::ostream& os) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (grid[i][j]) {
                os << grid[i][j]->getAnimalPopulation() << " ";
            } else {
                os << "N/A ";
            }
        }
        os << '\n';
    }
}

void map::printMegafaunaPopulation(std::ostream& os) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (grid[i][j]) {
                os << grid[i][j]->getMegafaunaPopulation() << " ";
            } else {
                os << "N/A ";
            }
        }
        os << '\n';
    }
}