#ifndef BUILDING_H
#define BUILDING_H

#include <string>

class Building {
public:
    Building(int level, const std::string& position) : level(level), position(position) {}
    virtual ~Building() = default;

    virtual int produce() const = 0; // Returns the amount of resource produced
    virtual std::string getType() const = 0; // Returns the building's type

    int getLevel() const { return level; } // Get the building's level
    std::string getPosition() const { return position; } // Get the building's position

protected:
    int level;
    std::string position;
};
class Farmland : public Building {
public:
    Farmland(int level, const std::string& position) : Building(level, position) {}
    int produce() const override;
    std::string getType() const override { return "Farmland"; }
};

class Mine : public Building {
public:
    Mine(int level, const std::string& position) : Building(level, position) {}
    int produce() const override;
    std::string getType() const override { return "Mine"; }
};

class Quarry : public Building {
public:
    Quarry(int level, const std::string& position) : Building(level, position) {}
    int produce() const override;
    std::string getType() const override { return "Quarry"; }
};

class LumberMill : public Building {
public:
    LumberMill(int level, const std::string& position) : Building(level, position) {}
    int produce() const override;
    std::string getType() const override { return "Lumber Mill"; }
};

#endif // BUILDING_H
