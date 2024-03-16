#ifndef TROOP_H
#define TROOP_H

#include <string>
#include <vector>

struct Troop {
    std::string name;
    int attack; // Melee Attack
    int defense;
    int life;
    int speed;
    int load; // Carrying capacity
    int upkeep;
    int power;
    int quantity; // Quantity of troops
};

extern std::vector<Troop> playerTroops;

#endif
