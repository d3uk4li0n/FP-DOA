#include "Farmland.h"
#include "../logic/PlayerResources.h"

// Constructor remains unchanged
Farmland::Farmland(int level, const std::string& position) : Building(level, position) {}

// Updated produce method to directly modify PlayerResources
void Farmland::produce(PlayerResources& resources) const {
    // Directly increase food based on the Farmland's level
    resources.setFood(resources.getFood() + 20 * getLevel());
}

std::string Farmland::getType() const {
    return "Farmland";
}
