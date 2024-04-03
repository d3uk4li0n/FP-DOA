// Quarry.cpp
#include "Quarry.h"
#include "../logic/PlayerResources.h"

Quarry::Quarry(int level, const std::string& position) : Building(level, position) {}

void Quarry::produce(PlayerResources& resources) const {
    resources.setStone(resources.getStone() + 20 * getLevel()); // Directly update resources
}

std::string Quarry::getType() const {
    return "Quarry";
}
