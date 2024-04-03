#ifndef PLAYER_RESOURCES_H
#define PLAYER_RESOURCES_H

#include <vector>
#include <memory>
#include "../buildings/Building.h"
#include <imgui.h>
#include <imgui-SFML.h>

class PlayerResources
{
public:
    PlayerResources();

    // Resource getters
    int getWood() const;
    int getStone() const;
    int getMetal() const;
    int getFood() const;
    int getGold() const;

    // Resource setters
    void setWood(int value);
    void setStone(int value);
    void setMetal(int value);
    void setFood(int value);
    void setGold(int value);

    // Methods for building management
    size_t getBuildingCount() const;
    Building *getBuilding(size_t index);
    void addBuilding(std::unique_ptr<Building> building); // Ensure this is declared only once
    void removeBuilding(size_t index);                    // Ensure this is declared only once
    void increaseResources();                             // Ensure this is declared
    void displayResources();                              // Ensure this is declared
    void update(float deltaTime);

private:
    int wood, stone, metal, food, gold;
    float updateTimer;
    std::vector<std::unique_ptr<Building>> buildings;
};

#endif // PLAYER_RESOURCES_H
