#ifndef MINE_H
#define MINE_H

#include "Building.h"

class Mine : public Building
{
public:
    Mine(int level, const std::string &position);
    int produce() const override;
    std::string getType() const override;
};

#endif // MINE_H
