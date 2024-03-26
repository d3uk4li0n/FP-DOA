#ifndef LUMBERMILL_H
#define LUMBERMILL_H

#include "Building.h"

class LumberMill : public Building
{
public:
    LumberMill(int level, const std::string &position);
    int produce() const override;
    std::string getType() const override;
};

#endif // LUMBERMILL_H
