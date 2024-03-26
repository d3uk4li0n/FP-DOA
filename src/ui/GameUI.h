#ifndef GAME_UI_H
#define GAME_UI_H

#include "../logic/PlayerResources.h"
#include "BuildingManagementGUI.h"
#include "TroopCreationForm.h"
#include "TroopInputForm.h"
#include <string>
#include <vector>

void displayMainGameUI(std::vector<Troop> &playerTroops, PlayerResources &playerResources, std::vector<std::string> &targets, std::string &selectedTarget, int &selectedLevel, std::string &battleOutcomeMessage);

#endif // GAME_UI_H
