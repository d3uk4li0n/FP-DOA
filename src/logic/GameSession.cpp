// GameSession.cpp
#include "GameSession.h"
#include "../ui/GameUI.h"
#include <string>
#include <vector>

GameSession::GameSession() : selectedTarget("AnthropusCamp"), selectedLevel(1),
    targets({"AnthropusCamp", "WildernessForest", "WildernessMountain", "WildernessHill", "WildernessLake"}) {}

void GameSession::update(float dt) {
    playerResources.update(dt);
}

void GameSession::displayUI() {
    // The positions array is now moved to the building management GUI component,
    // or wherever it's most relevant.
    // This function call encapsulates all UI logic into the GameUI module.
    displayMainGameUI(playerTroops, playerResources, targets, selectedTarget, selectedLevel, battleOutcomeMessage);
}