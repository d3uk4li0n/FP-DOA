// PlayerResources.cpp
#include "PlayerResources.h"

void PlayerResources::addBuilding(Building* building) {
    buildings.push_back(building);
}

void PlayerResources::increaseResources() {
    for (auto* building : buildings) {
        food += building->produce(); // Simplified logic; adjust based on your game's mechanics
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

void PlayerResources::update(float deltaTime) {
    updateTimer += deltaTime;
    if (updateTimer >= 1.0f) { // Checking every second
        increaseResources();
        updateTimer -= 1.0f;
    }
}

void PlayerResources::removeBuilding(size_t index) {
    if (index < buildings.size()) {
        delete buildings[index]; // Free the dynamically allocated memory
        buildings.erase(buildings.begin() + index); // Remove the pointer from the vector
    }
}

PlayerResources::~PlayerResources() {
    for (auto* building : buildings) {
        delete building; // Clean up dynamic allocations
    }
}
