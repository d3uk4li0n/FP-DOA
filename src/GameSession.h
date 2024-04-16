#ifndef GAME_SESSION_H
#define GAME_SESSION_H

#include "PlayerResources.h"
#include "Troop.h"
#include <string>
#include <vector>
#include "FortunaChance.h"

class GameSession {
public:
    GameSession();
    ~GameSession();

    std::string selectedTarget;
    int selectedLevel;
    std::vector<std::string> targets;
    std::string battleOutcomeMessage;
    PlayerResources playerResources;

    void update(float dt);
    void displayUI(sf::RenderWindow& window);

    //handle click event
    void doLeftClick(sf::Vector2f& mouse);
private:
    FortunaChance* fortunaChance;
};

#endif // GAME_SESSION_H
