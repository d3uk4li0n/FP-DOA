// PlayerResources.cpp
#include "PlayerResources.h"
#include "Farmland.h"
#include "Mine.h"
#include "Quarry.h"
#include "LumberMill.h"

void PlayerResources::addBuilding(Building *building)
{
    buildings.push_back(building);
}

void PlayerResources::increaseResources()
{
    for (auto *building : buildings)
    {
        if (auto *farm = dynamic_cast<Farmland *>(building))
        {
            food += farm->produce();
        }
        else if (auto *mine = dynamic_cast<Mine *>(building))
        {
            metal += mine->produce();
        }
        else if (auto *quarry = dynamic_cast<Quarry *>(building))
        {
            stone += quarry->produce();
        }
        else if (auto *lumberMill = dynamic_cast<LumberMill *>(building))
        {
            wood += lumberMill->produce();
        }
    }
}

void PlayerResources::displayResources()
{
    ImGui::Begin("Player Resources");
    ImGui::Text("Wood: %d", wood);
    ImGui::Text("Stone: %d", stone);
    ImGui::Text("Metal: %d", metal);
    ImGui::Text("Food: %d", food);
    ImGui::Text("Gold: %d", gold);
    ImGui::End();
}

void PlayerResources::update(float deltaTime)
{
    updateTimer += deltaTime;
    if (updateTimer >= 1.0f)
    { // Checking every second
        increaseResources();
        updateTimer -= 1.0f;
    }
}

void PlayerResources::removeBuilding(size_t index)
{
    if (index < buildings.size())
    {
        delete buildings[index];                    // Free the dynamically allocated memory
        buildings.erase(buildings.begin() + index); // Remove the pointer from the vector
    }
}

PlayerResources::~PlayerResources()
{
    for (auto *building : buildings)
    {
        delete building; // Clean up dynamic allocations
    }
}
