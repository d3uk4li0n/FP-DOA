#include "PlayerResources.h"
#include "../buildings/Farmland.h"
#include "../buildings/Mine.h"
#include "../buildings/Quarry.h"
#include "../buildings/LumberMill.h"
#include "../buildings/Building.h"

PlayerResources::PlayerResources() : wood(0), stone(0), metal(0), food(0), gold(0) {}

// Getters
int PlayerResources::getWood() const { return wood; }
int PlayerResources::getStone() const { return stone; }
int PlayerResources::getMetal() const { return metal; }
int PlayerResources::getFood() const { return food; }
int PlayerResources::getGold() const { return gold; }

// Setters
void PlayerResources::setWood(int value) { wood = value; }
void PlayerResources::setStone(int value) { stone = value; }
void PlayerResources::setMetal(int value) { metal = value; }
void PlayerResources::setFood(int value) { food = value; }
void PlayerResources::setGold(int value) { gold = value; }

void PlayerResources::addBuilding(std::unique_ptr<Building> building)
{
    buildings.push_back(std::move(building));
}

void PlayerResources::removeBuilding(size_t index)
{
    if (index < buildings.size())
    {
        buildings.erase(buildings.begin() + index);
    }
}

void PlayerResources::updateResources()
{
    for (auto &building : buildings)
    {
        building->produce(*this); // Calls the produce method of each building
    }
}

void PlayerResources::displayResources()
{
    ImGui::Begin("Player Resources");
    ImGui::Text("Wood: %d", getWood());
    ImGui::Text("Stone: %d", getStone());
    ImGui::Text("Metal: %d", getMetal());
    ImGui::Text("Food: %d", getFood());
    ImGui::Text("Gold: %d", getGold());
    ImGui::End();
}

size_t PlayerResources::getBuildingCount() const
{
    return buildings.size();
}

Building *PlayerResources::getBuilding(size_t index)
{
    if (index < buildings.size())
    {
        return buildings[index].get();
    }
    return nullptr; // Or appropriate error handling
}