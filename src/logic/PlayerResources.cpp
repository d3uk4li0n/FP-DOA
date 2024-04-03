#include "PlayerResources.h"
#include "../buildings/Farmland.h"
#include "../buildings/Mine.h"
#include "../buildings/Quarry.h"
#include "../buildings/LumberMill.h"

PlayerResources::PlayerResources() : wood(0), stone(0), metal(0), food(0), gold(0), updateTimer(0.0f) {}

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

void PlayerResources::increaseResources()
{
    for (const auto &building : buildings)
    {
        if (auto farmland = dynamic_cast<Farmland *>(building.get()))
        {
            food += farmland->produce();
        }
        else if (auto mine = dynamic_cast<Mine *>(building.get()))
        {
            metal += mine->produce();
        }
        else if (auto quarry = dynamic_cast<Quarry *>(building.get()))
        {
            stone += quarry->produce();
        }
        else if (auto lumberMill = dynamic_cast<LumberMill *>(building.get()))
        {
            wood += lumberMill->produce();
        }
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

void PlayerResources::update(float deltaTime)
{
    updateTimer += deltaTime;
    if (updateTimer >= 1.0f)
    {
        increaseResources();
        updateTimer -= 1.0f;
    }
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
    return nullptr; // Or throw an exception as per your error handling policy
}

void PlayerResources::removeBuilding(size_t index)
{
    if (index < buildings.size())
    {
        buildings.erase(buildings.begin() + index);
    }
}
