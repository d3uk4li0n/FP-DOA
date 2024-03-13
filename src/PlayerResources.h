// PlayerResources.h
#ifndef PLAYER_RESOURCES_H
#define PLAYER_RESOURCES_H

#include <string>
#include <imgui.h>
#include <imgui-SFML.h>

class PlayerResources {
public:
    int wood = 0;
    int stone = 0;
    int metal = 0;
    int food = 0;
    int gold = 0;
    float updateTimer = 0.0f; // Timer to track resource update

    void increaseResources(int amount);
    void displayResources();
    void update(float deltaTime); // deltaTime in seconds
};

#endif
