// Mine.cpp
#include "Mine.h"
#include "../logic/PlayerResources.h"

Mine::Mine(int level, const std::string& position) : Building(level, position) {}

void Mine::produce(PlayerResources& resources) const {
    resources.setMetal(resources.getMetal() + 20 * getLevel()); // Directly update resources
}

std::string Mine::getType() const {
    return "Mine";
}
