#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

struct Troop {
    std::string name;
    int attack;
    int life;
    int power;
    int quantity;
};

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

std::unordered_map<std::string, std::vector<TargetData>> targetDatabase; // Simulated database

// Initialize the target database from JSON data
void initializeTargetDatabase() {
    // This function should parse the JSON files and populate the targetDatabase
    // For the purpose of this example, let's manually add one entry for each type
    targetDatabase["AnthropusCamp"] = {{100000, {0, 0, 0, 112500, 2500}}}; // Simplified data
    targetDatabase["WildernessForest"] = {{500, {10, 0, 0, 0, 0}}}; // Example for level 1 forest
}

int calculateTotalCombatStrength(const std::vector<Troop>& troops) {
    int totalCombatStrength = 0;
    for (const auto& troop : troops) {
        totalCombatStrength += troop.attack * troop.life * troop.power * troop.quantity;
    }
    return totalCombatStrength;
}

TargetData getTargetData(const std::string& targetType, int level) {
    // Assuming levels are 1-indexed and array is 0-indexed
    if (targetDatabase.find(targetType) != targetDatabase.end() && level <= targetDatabase[targetType].size()) {
        return targetDatabase[targetType][level - 1];
    }
    return {}; // Return an empty structure if not found
}

std::pair<std::string, ResourceBonus> calculateBattleOutcome(const std::vector<Troop>& playerTroops, const std::string& targetType, int level) {
    int playerCombatStrength = calculateTotalCombatStrength(playerTroops);
    TargetData target = getTargetData(targetType, level);

    if (playerCombatStrength > target.defendersPower) {
        // Player wins, return resources earned
        return {"Player Wins", target.resourceBonus};
    } else {
        // Player loses, return no resources
        return {"Player Loses", {}};
    }
}

int main() {
    initializeTargetDatabase();
    
    // Example usage with hardcoded data
    std::vector<Troop> playerTroops = {
        {"Longbowman", 85, 75, 4, 1}
    };

    std::string targetType = "AnthropusCamp"; // or "WildernessForest" as an example
    int level = 1;

    auto [outcome, resources] = calculateBattleOutcome(playerTroops, targetType, level);
    std::cout << "Battle outcome: " << outcome << std::endl;
    std::cout << "Resources earned: Food " << resources.food << ", Gold " << resources.gold << std::endl; // Simplified output

    return 0;
}
