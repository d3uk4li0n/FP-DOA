#ifndef GAME_UI_H
#define GAME_UI_H

#include "PlayerResources.h"
#include "Troop.h"
#include <vector>
#include <string>

void displayTroopInputForm(std::vector<Troop>& playerTroops, std::string& selectedTarget, int& selectedLevel, std::vector<std::string>& targets, std::string& battleOutcomeMessage, PlayerResources& playerResources);
void displayBuildingManagementGUI(PlayerResources& playerResources, std::vector<std::string>& positions); // Ensure this line is present

#endif // GAME_UI_H
