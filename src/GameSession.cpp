#include "GameSession.h"
#include "GameUI.h"

GameSession::GameSession() : selectedTarget("AnthropusCamp"), selectedLevel(1), targets({"AnthropusCamp", "WildernessForest", "WildernessMountain", "WildernessHill", "WildernessLake"}) {}

void GameSession::update(float dt) {
    playerResources.update(dt);
}

void GameSession::displayUI() {
    displayTroopInputForm(playerTroops, selectedTarget, selectedLevel, targets, battleOutcomeMessage, playerResources);
}
