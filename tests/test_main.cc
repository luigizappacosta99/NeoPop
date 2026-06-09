#include <iostream>
#include "map.h"
#include "pixel.h"

void testPixelCreation() {
    pixel p(0, 0, 50, true, "FOREST", 0.8, 0.7, 15.0);
    std::cout << "Testing Pixel Creation:" << std::endl;
    std::cout << "Position: (" << p.getX() << ", " << p.getY() << ")" << std::endl;
    std::cout << "Height: " << p.getHeight() << std::endl;
    std::cout << "Is Passable: " << (p.isPassable() ? "Yes" : "No") << std::endl;
    std::cout << "Biome: " << p.getBiome() << std::endl;
    std::cout << "Fertility: " << p.getFertility() << std::endl;
    std::cout << "Humidity: " << p.getHumidity() << std::endl;
    std::cout << "Temperature: " << p.getTemperature() << std::endl;
}

void testMapCreation() {
    map m(5, 5);
    std::cout << "Testing Map Creation:" << std::endl;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            pixel* p = m.getPixel(j, i);
            std::cout << "Pixel at (" << j << ", " << i << "): " << p->getBiome() << std::endl;
        }
    }
}

int main() {
    testPixelCreation();
    testMapCreation();
    return 0;
}