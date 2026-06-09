#ifndef PIXEL_H
#define PIXEL_H

#include <string>
#include <vector>

class pixel
{
private:
    int x;
    int y;
    int h;
    bool is_passable;
    std::string biome;
    
    double fertility;
    double humidity;
    double temperature;

    int animal_population;
    int megafauna_population;
public:
    pixel();
    pixel(int x, int y, int h, bool is_passable, std::string biome, double fertility, double humidity, double temperature);
    ~pixel();

    //std::vector<pixel*> getNeighbors();

    //Functions for loop
    //void update_animal_population();

    // Getters
    int getX() const;
    int getY() const;
    int getHeight() const;
    bool isPassable() const;
    std::string getBiome() const;
    double getFertility() const;
    double getHumidity() const;
    double getTemperature() const;
    int getAnimalPopulation() const;
    int getMegafaunaPopulation() const;

    //setters
    void setHeight(int height);
    void setPassable(bool passable);
    void setBiome(const std::string& new_biome);
    void setFertility(double fertility);
    void setHumidity(double humidity);
    void setTemperature(double temperature);
    void setAnimalPopulation(int population);
    void setMegafaunaPopulation(int population);
};

#endif // PIXEL_H