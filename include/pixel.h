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

    float fertility;
    float usage;

    int animal_population;
    int megafauna_population;

public:
    pixel();
    pixel(int x, int y, int h, float fertility);
    ~pixel();

    //std::vector<pixel*> getNeighbors();

    //Functions for loop
    //void update_usage();
    //void update_animalPopulation();
    //void update_megafaunaPopulation();

    // Getters
    int getX() const;
    int getY() const;
    int getHeight() const;
    bool isPassable() const;
    float getFertility() const;
    float getUsage() const;
    int getAnimalPopulation() const;
    int getMegafaunaPopulation() const;

    //setters
    void setHeight(int height);
    void setPassable(bool passable);
    void setFertility(float fert);
    void setUsage(float us);
    //void setAnimalPopulation;
    //void setMegafaunaPopulation;

};

#endif // PIXEL_H