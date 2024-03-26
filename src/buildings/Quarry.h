#ifndef QUARRY_H
#define QUARRY_H

#include "Building.h"

class Quarry : public Building
{
public:
    Quarry(int level, const std::string &position);
    int produce() const override;
    std::string getType() const override;
};

#endif // QUARRY_H
