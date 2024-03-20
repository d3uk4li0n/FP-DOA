#ifndef BUILDING_H
#define BUILDING_H

#include <string>

class Building {
public:
    Building(int level, const std::string& position);
    virtual ~Building();

    virtual int produce() const = 0;
    virtual std::string getType() const = 0;

    int getLevel() const;
    std::string getPosition() const;

private:
    int level;
    std::string position;
};

#endif // BUILDING_H
