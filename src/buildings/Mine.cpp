#include "Mine.h"

Mine::Mine(int level, const std::string& position) : Building(level, position) {}

int Mine::produce() const {
    return 20 * getLevel();
}

std::string Mine::getType() const {
    return "Mine";
}
