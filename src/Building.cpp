#include "Building.h"

int Farmland::produce() const
{
    // Produces food
    return 20 * getLevel();
}

int Mine::produce() const
{
    // Produces metal
    return 10 * getLevel();
}

int Quarry::produce() const
{
    // Produces stone
    return 15 * getLevel();
}

int LumberMill::produce() const
{
    // Produces wood
    return 12 * getLevel();
}
