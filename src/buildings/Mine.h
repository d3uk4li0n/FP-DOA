// Mine.h
#ifndef MINE_H
#define MINE_H

#include "Building.h"
#include "../logic/PlayerResources.h"

class Mine : public Building
{
public:
    Mine(int level, const std::string &position);
    void produce(PlayerResources& resources) const override; // Correct signature
    std::string getType() const override;
};

#endif // MINE_H
