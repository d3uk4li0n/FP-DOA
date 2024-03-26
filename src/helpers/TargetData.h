#ifndef TARGET_DATA_H
#define TARGET_DATA_H

#include <vector>
#include <string>
#include <unordered_map>
#include "../troops/Troop.h"

struct ResourceBonus {
    int wood = 0;
    int stone = 0;
    int metal = 0;
    int food = 0;
    int gold = 0;
};

struct TargetData {
    int defendersPower;
    ResourceBonus resourceBonus;
};

extern std::unordered_map<std::string, std::vector<TargetData>> targetDatabase;

// Function prototypes
void initializeTargetDatabase();
TargetData getTargetData(const std::string &targetType, int level);
int calculateTotalCombatStrength(const std::vector<Troop> &troops);

#endif // TARGET_DATA_H
