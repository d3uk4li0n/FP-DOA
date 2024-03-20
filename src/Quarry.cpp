
#include "Quarry.h"

Quarry::Quarry(int level, const std::string& position) : Building(level, position) {}

int Quarry::produce() const {
    return 20 * getLevel();
}

std::string Quarry::getType() const {
    return "Quarry";
}
