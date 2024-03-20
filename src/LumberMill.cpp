
#include "LumberMill.h"

LumberMill::LumberMill(int level, const std::string& position) : Building(level, position) {}

int LumberMill::produce() const {
    return 20 * getLevel();
}

std::string LumberMill::getType() const {
    return "LumberMill";
}
