// Quarry.h
#ifndef QUARRY_H
#define QUARRY_H

#include "Building.h"
#include "../logic/PlayerResources.h"

class Quarry : public Building {
public:
    Quarry(int level, const std::string &position);
    void produce(PlayerResources& resources) const override; // Correct signature
    std::string getType() const override;
};

#endif // QUARRY_H
