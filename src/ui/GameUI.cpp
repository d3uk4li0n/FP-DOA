#include "GameUI.h"
#include <imgui.h>

void displayMainGameUI(std::vector<Troop> &playerTroops, PlayerResources &playerResources, std::vector<std::string> &targets, std::string &selectedTarget, int &selectedLevel, std::string &battleOutcomeMessage)
{
    // Display the troop input form.
    displayTroopInputForm(playerTroops, selectedTarget, selectedLevel, targets, battleOutcomeMessage, playerResources);

    // Display the building management GUI.
    std::vector<std::string> positions = {"Position 1", "Position 2", "Position 3", "Position 4", "Position 5", "Position 6", "Position 7", "Position 8", "Position 9", "Position 10"};
    displayBuildingManagementGUI(playerResources, positions);

    // Display the troop creation form.
/*     displayTroopCreationForm(playerTroops, playerResources);
 */}
