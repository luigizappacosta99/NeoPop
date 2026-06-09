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
            int h = ValueNoise_2D_perlin(j, i, 7, 0.5, seed) * 1000 + 100;
            //cap water at -100
            if (h < 0) h = -100;
            bool is_passable = h < 800;
            double humidity = ValueNoise_2D_perlin(j + 100, i + 100, 7, 0.5, seed+23);
            double temperature = ValueNoise_2D_perlin(j + 200, i + 200, 7, 0.5, seed+25) * 40 - 10;
            pixel* p = new pixel(j, i, h, is_passable, "", 0.0, humidity, temperature);
            grid[i][j] = p;
        }
    }

    //now assign biomes based on height, humidity, and temperature
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                if (grid[i][j]) {
                    int h = grid[i][j]->getHeight();
                    double humidity = grid[i][j]->getHumidity();
                    double temperature = grid[i][j]->getTemperature();
                    std::string biome;
                    if (h < 0) {
                        biome = "OCEAN";
                    } else if (h < 200) {
                        biome = "BEACH";
                    } else if (h < 400) {
                        biome = "PLAINS";
                    } else if (h < 600) {
                        biome = "FOREST";
                    } else if (h < 800) {
                        biome = "MOUNTAIN";
                    } else {
                        biome = "SNOW";
                    }
                    grid[i][j]->setBiome(biome);
                }
            }
        }

    
}

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

void map::printHeight() {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (grid[i][j]) {
                std::cout << grid[i][j]->getHeight() << " ";
            } else {
                std::cout << "N/A ";
            }
        }
        std::cout << std::endl;
    }
}

void map::printBiomes() {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (grid[i][j]) {
                std::cout << grid[i][j]->getBiome() << " ";
            } else {
                std::cout << "N/A ";
            }
        }
        std::cout << std::endl;
    }
}

void map::printFertility() {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (grid[i][j]) {
                std::cout << grid[i][j]->getFertility() << " ";
            } else {
                std::cout << "N/A ";
            }
        }
        std::cout << std::endl;
    }
}

void map::printHumidity() {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (grid[i][j]) {
                std::cout << grid[i][j]->getHumidity() << " ";
            } else {
                std::cout << "N/A ";
            }
        }
        std::cout << std::endl;
    }
}

void map::printTemperature() {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (grid[i][j]) {
                std::cout << grid[i][j]->getTemperature() << " ";
            } else {
                std::cout << "N/A ";
            }
        }
        std::cout << std::endl;
    }
}

void map::printAnimalPopulation() {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (grid[i][j]) {
                std::cout << grid[i][j]->getAnimalPopulation() << " ";
            } else {
                std::cout << "N/A ";
            }
        }
        std::cout << std::endl;
    }
}

void map::printMegafaunaPopulation() {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (grid[i][j]) {
                std::cout << grid[i][j]->getMegafaunaPopulation() << " ";
            } else {
                std::cout << "N/A ";
            }
        }
        std::cout << std::endl;
    }
}