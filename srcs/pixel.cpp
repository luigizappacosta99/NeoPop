#include "../include/pixel.h"

pixel::pixel() : x(0), y(0), h(0), is_passable(true), biome(""), fertility(0.0), humidity(0.0), temperature(0.0), animal_population(0), megafauna_population(0) {}

pixel::pixel(int x, int y, int h, bool is_passable, std::string biome, double fertility, double humidity, double temperature) : x(x), y(y), h(h), is_passable(is_passable), biome(biome), fertility(fertility), humidity(humidity), temperature(temperature), animal_population(0), megafauna_population(0) {}

pixel::~pixel() {}


//getters

int pixel::getX() const {return x;}  
int pixel::getY() const {return y;}  
int pixel::getHeight() const {return h;}  
bool pixel::isPassable() const {return is_passable;}  
std::string pixel::getBiome() const {return biome;}  
double pixel::getFertility() const {return fertility;}  
double pixel::getHumidity() const {return humidity;}  
double pixel::getTemperature() const {return temperature;}  
int pixel::getAnimalPopulation() const {return animal_population;}  
int pixel::getMegafaunaPopulation() const {return megafauna_population;}  

//setters

void pixel::setHeight(int height) {h = height;}
void pixel::setPassable(bool passable) {is_passable = passable;}
void pixel::setBiome(const std::string& new_biome) {biome = new_biome;}
void pixel::setFertility(double fertility) {fertility = fertility;}
void pixel::setHumidity(double humidity) {humidity = humidity;}
void pixel::setTemperature(double temperature) {temperature = temperature;}