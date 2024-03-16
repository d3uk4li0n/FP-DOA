// Building.cpp
#include "Building.h"

int Farmland::produce() const {
    return 10 * level; // Example production logic
}

int Mine::produce() const {
    return 5 * level; // Example production logic
}

int Quarry::produce() const {
    return 4 * level; // Example production logic
}

int LumberMill::produce() const {
    return 8 * level; // Example production logic
}
