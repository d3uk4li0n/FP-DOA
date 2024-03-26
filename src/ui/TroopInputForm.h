#ifndef TROOP_INPUT_FORM_H
#define TROOP_INPUT_FORM_H

#include "../logic/PlayerResources.h"
#include "../troops/Troop.h"
#include <vector>
#include <string>

void displayTroopInputForm(std::vector<Troop>& playerTroops, std::string& selectedTarget, int& selectedLevel, std::vector<std::string>& targets, std::string& battleOutcomeMessage, PlayerResources& playerResources);

#endif // TROOP_INPUT_FORM_H
