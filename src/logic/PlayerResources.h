#ifndef PLAYER_RESOURCES_H
#define PLAYER_RESOURCES_H

#include <vector>
#include <memory>
#include <imgui.h>
#include <imgui-SFML.h>
#include "../buildings/Building.h"

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

    void addBuilding(std::unique_ptr<Building> building);
    void removeBuilding(size_t index);
    void updateResources(); // This is the new method for updating resources
    void displayResources();
    size_t getBuildingCount() const;
    Building *getBuilding(size_t index);

private:
    int wood, stone, metal, food, gold;
    std::vector<std::unique_ptr<Building>> buildings;
};

#endif // PLAYER_RESOURCES_H
