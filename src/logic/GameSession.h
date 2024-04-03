#ifndef GAME_SESSION_H
#define GAME_SESSION_H

#include "PlayerResources.h"
#include "../troops/Troop.h"
#include <string>
#include <vector>

class GameSession
{
public:
    GameSession();

    std::string selectedTarget;
    int selectedLevel;
    std::vector<std::string> targets;
    std::string battleOutcomeMessage;
    PlayerResources playerResources;

    void update();
    void displayUI();
};

#endif // GAME_SESSION_H
