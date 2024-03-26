#ifndef PLAYER_RESOURCES_H
#define PLAYER_RESOURCES_H

#include <vector>
#include <memory> // Include for std::unique_ptr
#include "Building.h"
#include <imgui.h>
#include <imgui-SFML.h>

class PlayerResources {
public:
    PlayerResources() : wood(0), stone(0), metal(0), food(0), gold(0), updateTimer(0.0f) {}

    int wood, stone, metal, food, gold;
    float updateTimer;
    std::vector<std::unique_ptr<Building>> buildings; // Change to store unique_ptr

    void addBuilding(std::unique_ptr<Building> building);
    void increaseResources();
    void displayResources();
    void update(float deltaTime);
    void removeBuilding(size_t index);

private:
    // Destructor is not needed because std::unique_ptr automatically handles memory cleanup
};

#endif // PLAYER_RESOURCES_H
