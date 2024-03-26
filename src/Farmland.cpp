#include "Farmland.h"

Farmland::Farmland(int level, const std::string& position) : Building(level, position) {}

int Farmland::produce() const {
    return 20 * getLevel();
}

std::string Farmland::getType() const {
    return "Farmland";
}
