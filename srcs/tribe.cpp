#include "../include/tribe.h"

tribe::tribe(int x, int y, int population) : x(x), y(y), population(population) {}

tribe::~tribe() {}

void tribe::move(int new_x, int new_y) {
    x = new_x;
    y = new_y;
}

int tribe::getX() const {
    return x;
}

int tribe::getY() const {
    return y;
}

int tribe::getPopulation() const {
    return population;
}