#ifndef PLAYER_RESOURCES_H
#define PLAYER_RESOURCES_H

#include <imgui.h>
#include <imgui-SFML.h>

class PlayerResources {
public:
    PlayerResources(); // Default constructor declaration

    int wood;
    int stone;
    int metal;
    int food;
    int gold;
    float updateTimer; // Timer to track resource update

    void increaseResources(int amount);
    void displayResources();
    void update(float deltaTime); // deltaTime in seconds
};

#endif
