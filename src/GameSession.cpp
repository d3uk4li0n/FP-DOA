// GameSession.cpp
#include "GameSession.h"
#include "GameUI.h"
#include <string>
#include <vector>

GameSession::GameSession() : selectedTarget("AnthropusCamp"), selectedLevel(1),
    targets({"AnthropusCamp", "WildernessForest", "WildernessMountain", "WildernessHill", "WildernessLake"}) {}

void GameSession::update(float dt) {
    playerResources.update(dt);
}

void GameSession::displayUI() {
    displayTroopInputForm(playerTroops, selectedTarget, selectedLevel, targets, battleOutcomeMessage, playerResources);
    std::vector<std::string> positions = {"Position 1", "Position 2", "Position 3"}; // Example positions, adjust based on actual game logic
    displayBuildingManagementGUI(playerResources, positions);
}
