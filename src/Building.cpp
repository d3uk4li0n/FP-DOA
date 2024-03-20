#include "Building.h"

Building::Building(int level, const std::string& position) : level(level), position(position) {}

Building::~Building() = default;

int Building::getLevel() const { return level; }

std::string Building::getPosition() const { return position; }
