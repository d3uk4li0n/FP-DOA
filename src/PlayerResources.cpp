#include "PlayerResources.h"
#include "Farmland.h"
#include "Mine.h"
#include "Quarry.h"
#include "LumberMill.h"

void PlayerResources::addBuilding(std::unique_ptr<Building> building)
{
    buildings.push_back(std::move(building)); // Use std::move to transfer ownership
}

void PlayerResources::increaseResources()
{
    for (const auto &building : buildings)
    {
        if (auto farmland = dynamic_cast<Farmland *>(building.get()))
        {
            food += farmland->produce(); // Farmland produces food
        }
        else if (auto mine = dynamic_cast<Mine *>(building.get()))
        {
            metal += mine->produce(); // Mine produces metal
        }
        else if (auto quarry = dynamic_cast<Quarry *>(building.get()))
        {
            stone += quarry->produce(); // Quarry produces stone
        }
        else if (auto lumberMill = dynamic_cast<LumberMill *>(building.get()))
        {
            wood += lumberMill->produce(); // LumberMill produces wood
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
    {
        increaseResources();
        updateTimer -= 1.0f;
    }
}

void PlayerResources::removeBuilding(size_t index)
{
    if (index < buildings.size())
    {
        // No need to manually delete; unique_ptr will clean up automatically
        buildings.erase(buildings.begin() + index);
    }
}
