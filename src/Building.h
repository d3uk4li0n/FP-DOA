#ifndef BUILDING_H
#define BUILDING_H

#include <string>

class Building
{
public:
    Building(int level, const std::string &position) : level(level), position(position) {}
    virtual ~Building() = default;

    virtual int produce() const = 0;
    virtual std::string getType() const = 0;

    int getLevel() const { return level; }
    std::string getPosition() const { return position; }

private:
    int level;
    std::string position;
};

// Example of using constants for building types
static const std::string FARM_TYPE = "Farmland";
static const std::string MINE_TYPE = "Mine";
static const std::string QUARRY_TYPE = "Quarry";
static const std::string LUMBER_MILL_TYPE = "Lumber Mill";

class Farmland : public Building
{
public:
    Farmland(int level, const std::string &position) : Building(level, position) {}
    int produce() const override;
    std::string getType() const override { return FARM_TYPE; }
};

class Mine : public Building
{
public:
    Mine(int level, const std::string &position) : Building(level, position) {}
    int produce() const override;
    std::string getType() const override { return MINE_TYPE; }
};

class Quarry : public Building
{
public:
    Quarry(int level, const std::string &position) : Building(level, position) {}
    int produce() const override;
    std::string getType() const override { return QUARRY_TYPE; }
};

class LumberMill : public Building
{
public:
    LumberMill(int level, const std::string &position) : Building(level, position) {}
    int produce() const override;
    std::string getType() const override { return LUMBER_MILL_TYPE; }
};

#endif // BUILDING_H
