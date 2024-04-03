#ifndef FARMLAND_H
#define FARMLAND_H

#include "Building.h"
#include "../logic/PlayerResources.h"

class Farmland : public Building {
public:
    Farmland(int level, const std::string& position);
    void produce(PlayerResources& resources) const override; // Correct signature
    std::string getType() const override;
};

#endif // FARMLAND_H
