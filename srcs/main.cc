#include <iostream>
#include <fstream>
#include <ctime>
#include <random>
#include "includes.h"

int main(int argc, char const *argv[])
{
    srand(time(0));

    //generate a random W x H map and cout fertility
    if (argc < 3) {
        std::cerr << "Usage: " << argv[0] << " <width> <height>\n";
        return 1;
    }
    int map_width  = std::atoi(argv[1]);
    int map_height = std::atoi(argv[2]);
    map m(map_width, map_height);
    m.generateFromPerlinNoise();

    //print altitude, humidity and vegetation in a txt file
    std::ofstream altitude_file("altitude.txt");
    m.printHeight(altitude_file);
    altitude_file.close();
    std::ofstream fertility_file("fertility.txt");
    m.printFertility(fertility_file);
    fertility_file.close();

    //generate a tribe and plot it on the map
    int tribe_x = rand() % map_width;
    int tribe_y = rand() % map_height;
    while(!(m.getPixel(tribe_x,tribe_y)->isPassable())){
        tribe_x = rand() % map_width;
        tribe_y = rand() % map_height;
    }
    tribe t(tribe_x, tribe_y, 100);

    //epochs cycle
    const int epochs = 10;
    std::ofstream tribe_file("tribe.txt");
    for(int e = 0; e<epochs; ++e){
        int dx = rand() % 3 - 1;
        int dy = rand() % 3;
        while(!(m.getPixel(t.getX()+dx,t.getY()+dy)->isPassable())){
            dx = rand() % 3 - 1;
            dy = rand() % 3;
        }
        t.move(dx,dy);
        tribe_file <<t.getX()<<' '<<t.getY()<<std::endl;
    }
    tribe_file.close();
    return 0;
}
