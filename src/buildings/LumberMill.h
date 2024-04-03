// LumberMill.h
#ifndef LUMBERMILL_H
#define LUMBERMILL_H

#include "Building.h"
#include "../logic/PlayerResources.h"

class LumberMill : public Building {
public:
    LumberMill(int level, const std::string &position);
    void produce(PlayerResources& resources) const override; // Correct signature
    std::string getType() const override;
};

#endif // LUMBERMILL_H
