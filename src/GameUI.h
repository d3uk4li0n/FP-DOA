#ifndef GAME_UI_H
#define GAME_UI_H

#include "PlayerResources.h"
#include "Troop.h"
#include <string>
#include <vector>

void displayTroopInputForm(std::vector<Troop> &playerTroops, std::string &selectedTarget, int &selectedLevel, std::vector<std::string> &targets, std::string &battleOutcomeMessage, PlayerResources &playerResources);

#endif
