// PlayerResources.h
#ifndef PLAYER_RESOURCES_H
#define PLAYER_RESOURCES_H

#include <vector>
#include "Building.h" // Include the Building classes
#include <imgui.h>
#include <imgui-SFML.h>
class PlayerResources
{
public:
    PlayerResources() : wood(0), stone(0), metal(0), food(0), gold(0), updateTimer(0.0f) {}

    int wood, stone, metal, food, gold;
    float updateTimer;
    std::vector<Building *> buildings; // Store pointers to buildings

    void addBuilding(Building *building);
    void increaseResources();
    void displayResources();
    void update(float deltaTime);
    void removeBuilding(size_t index);
    ~PlayerResources(); // Destructor to properly clean up dynamic allocations
};

#endif // PLAYER_RESOURCES_H
