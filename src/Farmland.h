#ifndef FARMLAND_H
#define FARMLAND_H

#include "Building.h"

class Farmland : public Building {
public:
    Farmland(int level, const std::string& position);
    int produce() const override;
    std::string getType() const override;
};

#endif // FARMLAND_H
