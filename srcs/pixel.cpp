#include "../include/pixel.h"

pixel::pixel() : x(0), y(0), h(0), 
                 is_passable(true), 
                 fertility(0.0), 
                 usage(0.0),
                 animal_population(0), 
                 megafauna_population(0) 
                 {}

pixel::pixel(   int x, int y, int h, 
                float fertility) : 
            x(x), y(y), h(h), usage(0.0)
{
    //set is_passable
    is_passable = (h<3000 && h>=0);
    //set animals
    animal_population = 0;
    megafauna_population = 0;
}

pixel::~pixel() {}


//initialise fauna

//getters

int pixel::getX() const {return x;}  
int pixel::getY() const {return y;}  
int pixel::getHeight() const {return h;}  
bool pixel::isPassable() const {return is_passable;}  
float pixel::getFertility() const {return fertility;}  
float pixel::getUsage() const {return usage;}
int pixel::getAnimalPopulation() const {return animal_population;}  
int pixel::getMegafaunaPopulation() const {return megafauna_population;}  

//setters

void pixel::setHeight(int height) {h = height;}
void pixel::setPassable(bool passable) {is_passable = passable;}
void pixel::setFertility(float fert) {fertility = fert;}
void pixel::setUsage(float us) {usage = us;}

