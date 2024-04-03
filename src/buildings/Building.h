#ifndef BUILDING_H
#define BUILDING_H

#include <string>
class PlayerResources;

class Building
{
public:
    Building(int level, const std::string &position);
    virtual ~Building();

    // Updated produce method signature
    virtual void produce(PlayerResources &resources) const = 0;
    virtual std::string getType() const = 0;

    int getLevel() const;
    std::string getPosition() const;

protected:
    int level;
    std::string position;
};

#endif // BUILDING_H
