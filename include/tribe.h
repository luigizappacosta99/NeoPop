#ifndef TRIBE_H
#define TRIBE_H

#include <vector>

class tribe
{
private:
    int x;
    int y;
    int population;
    //std::vector<float> technology;

public:
    tribe(int x, int y, int population);
    ~tribe();

    void move(int dx, int dy);
    //void update_technology(std::vector<float> new_technology);

    //getters
    int getX() const;
    int getY() const;
    int getPopulation() const;
};

#endif // TRIBE_H