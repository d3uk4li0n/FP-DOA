#include "Building.h"

int Farmland::produce() const
{
    // Produces food
    return 20 * level;
}

int Mine::produce() const
{
    // Produces metal
    return 10 * level;
}

int Quarry::produce() const
{
    // Produces stone
    return 15 * level;
}

int LumberMill::produce() const
{
    // Produces wood
    return 12 * level;
}
