#include <imgui.h>

#include "GameUI.h"
#include "../helpers/TargetData.h"
#include "../logic/PlayerResources.h"
#include "../buildings/Building.h"
#include "../buildings/Farmland.h"
#include "../buildings/Mine.h"
#include "../buildings/Quarry.h"
#include "../buildings/LumberMill.h"
#include <algorithm> // For std::remove

void displayBuildingManagementGUI(PlayerResources &playerResources, std::vector<std::string> &allPositions)
{
    ImGui::Begin("Building Management");

    std::vector<std::string> availablePositions = allPositions; // Copy all possible positions

    // Display current buildings with an option to remove them
    for (int i = 0; i < playerResources.buildings.size(); ++i)
    {
        const auto &building = playerResources.buildings[i];
        ImGui::Text("%s Level %d at %s", building->getType().c_str(), building->getLevel(), building->getPosition().c_str());

        std::string removeButtonLabel = "Remove##" + std::to_string(i);
        if (ImGui::Button(removeButtonLabel.c_str()))
        {
            // Add the position back to available positions
            availablePositions.push_back(building->getPosition());
            // Remove the building
            playerResources.removeBuilding(i);
            --i; // Adjust index since we removed an item
        }
    }

    // Remove the occupied positions from availablePositions for the dropdown
    for (const auto &building : playerResources.buildings)
    {
        availablePositions.erase(std::remove(availablePositions.begin(), availablePositions.end(), building->getPosition()), availablePositions.end());
    }

    static int selectedBuildingType = 0; // 0-Farm, 1-Mine, 2-Lumber Mill
    static int buildingLevel = 1;        // Default level is 1
    static std::string selectedPosition = availablePositions.empty() ? "No Building slots available" : availablePositions[0];

    // Dropdown for selecting the position
    if (ImGui::BeginCombo("Position", selectedPosition.c_str()))
    {
        for (const auto &position : availablePositions)
        {
            bool isSelected = (selectedPosition == position);
            if (ImGui::Selectable(position.c_str(), isSelected))
            {
                selectedPosition = position;
            }
            if (isSelected)
            {
                ImGui::SetItemDefaultFocus();
            }
        }
        ImGui::EndCombo();
    }

    ImGui::Combo("Building Type", &selectedBuildingType, "Farm\0Mine\0Lumber Mill\0Quarry\0");
    ImGui::InputInt("Level", &buildingLevel, 1, 1);
    buildingLevel = std::max(1, buildingLevel); // Ensure level is at least 1

    // Button to add a new building
    if (ImGui::Button("Add Building") && !selectedPosition.empty() && std::find(availablePositions.begin(), availablePositions.end(), selectedPosition) != availablePositions.end())
    {
        std::unique_ptr<Building> building;
        switch (selectedBuildingType)
        {
        case 0:
            building = std::make_unique<Farmland>(buildingLevel, selectedPosition);
            break;
        case 1:
            building = std::make_unique<Mine>(buildingLevel, selectedPosition);
            break;
        case 2:
            building = std::make_unique<LumberMill>(buildingLevel, selectedPosition);
            break;
        case 3:
            building = std::make_unique<Quarry>(buildingLevel, selectedPosition);
            break;
        default:
            break;
        }
        if (building)
        {
            playerResources.addBuilding(std::move(building)); // Move the unique_ptr

            // Immediately remove the position from available positions to prevent duplicates
            availablePositions.erase(std::remove(availablePositions.begin(), availablePositions.end(), selectedPosition), availablePositions.end());
            // Reset selected position to first available or "Select..." if none are available
            selectedPosition = !availablePositions.empty() ? availablePositions[0] : "Select...";
        }
    }

    ImGui::End();
}

void displayTroopInputForm(std::vector<Troop> &playerTroops, std::string &selectedTarget, int &selectedLevel, std::vector<std::string> &targets, std::string &battleOutcomeMessage, PlayerResources &playerResources)
{
    ImGui::Begin("Troop Deployment Form");

    for (auto &troop : playerTroops)
    {
        ImGui::InputInt(troop.name.c_str(), &troop.quantity);
    }

    if (ImGui::BeginCombo("Target", selectedTarget.c_str()))
    {
        for (const auto &target : targets)
        {
            bool isSelected = (selectedTarget == target);
            if (ImGui::Selectable(target.c_str(), isSelected))
            {
                selectedTarget = target;
            }
            if (isSelected)
            {
                ImGui::SetItemDefaultFocus();
            }
        }
        ImGui::EndCombo();
    }

    ImGui::InputInt("Level", &selectedLevel);
    selectedLevel = std::max(1, std::min(selectedLevel, 10));

    if (ImGui::Button("Deploy"))
    {
        int playerCombatStrength = calculateTotalCombatStrength(playerTroops);
        TargetData target = getTargetData(selectedTarget, selectedLevel);
        bool victory = playerCombatStrength > target.defendersPower;
        battleOutcomeMessage = victory ? "Victory! " : "Defeat! ";
        battleOutcomeMessage += "Your power: " + std::to_string(playerCombatStrength) + " vs Enemy power: " + std::to_string(target.defendersPower) + ". ";

        if (victory)
        {
            battleOutcomeMessage += "Resources earned: Wood " + std::to_string(target.resourceBonus.wood) +
                                    ", Stone " + std::to_string(target.resourceBonus.stone) +
                                    ", Metal " + std::to_string(target.resourceBonus.metal) +
                                    ", Food " + std::to_string(target.resourceBonus.food) +
                                    ", Gold " + std::to_string(target.resourceBonus.gold) + ".";
            playerResources.wood += target.resourceBonus.wood;
            playerResources.stone += target.resourceBonus.stone;
            playerResources.metal += target.resourceBonus.metal;
            playerResources.food += target.resourceBonus.food;
            playerResources.gold += target.resourceBonus.gold;
        }
    }

    if (!battleOutcomeMessage.empty())
    {
        ImGui::Text("%s", battleOutcomeMessage.c_str());
    }

    ImGui::End();

    playerResources.displayResources();
}
