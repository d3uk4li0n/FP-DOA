// LumberMill.cpp
#include "LumberMill.h"
#include "../logic/PlayerResources.h"

LumberMill::LumberMill(int level, const std::string& position) : Building(level, position) {}

void LumberMill::produce(PlayerResources& resources) const {
    resources.setWood(resources.getWood() + 20 * getLevel()); // Directly update resources
}

std::string LumberMill::getType() const {
    return "LumberMill";
}
