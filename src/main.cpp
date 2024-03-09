#include <SFML/Graphics.hpp>
#include <imgui.h>
#include <imgui-SFML.h>
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
std::vector<Troop> playerTroops; // Vector to hold player's troops input

void initializeTargetDatabase() {
    // Initialize with example data
    targetDatabase["AnthropusCamp"] = {{1000, {0, 0, 0, 112500, 2500}}};
    targetDatabase["WildernessForest"] = {{500, {10, 0, 0, 0, 0}}};
}

int calculateTotalCombatStrength(const std::vector<Troop>& troops) {
    int totalCombatStrength = 0;
    for (const auto& troop : troops) {
        totalCombatStrength += troop.attack * troop.life * troop.power * troop.quantity;
    }
    return totalCombatStrength;
}

TargetData getTargetData(const std::string& targetType, int level) {
    if (targetDatabase.find(targetType) != targetDatabase.end() && level <= targetDatabase[targetType].size()) {
        return targetDatabase[targetType][level - 1];
    }
    return {};
}

std::pair<std::string, ResourceBonus> calculateBattleOutcome(const std::vector<Troop>& playerTroops, const std::string& targetType, int level) {
    int playerCombatStrength = calculateTotalCombatStrength(playerTroops);
    TargetData target = getTargetData(targetType, level);

    if (playerCombatStrength > target.defendersPower) {
        return {"Player Wins", target.resourceBonus};
    } else {
        return {"Player Loses", {}};
    }
}

// ImGui form to let the user input troop types and quantities
void displayTroopInputForm() {
    ImGui::Begin("Troop Input Form");
    for (int i = 0; i < playerTroops.size(); ++i) {
        ImGui::InputInt(("Quantity " + std::to_string(i+1)).c_str(), &playerTroops[i].quantity);
    }
    if (ImGui::Button("Add Troop")) {
        playerTroops.push_back({"", 0, 0, 0, 0}); // Adding a placeholder for a new troop
    }
    ImGui::End();
}

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Battle Simulator");
    ImGui::SFML::Init(window);

    initializeTargetDatabase();
    
    // Pre-fill some troops for demonstration
    playerTroops.push_back({"Conscript", 10, 75, 1, 100});
    playerTroops.push_back({"Longbowman", 85, 75, 4, 50});

    sf::Clock deltaClock;
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            ImGui::SFML::ProcessEvent(event);
            if (event.type == sf::Event::Closed)
                window.close();
        }

        ImGui::SFML::Update(window, deltaClock.restart());

        displayTroopInputForm();

        window.clear();
        ImGui::SFML::Render(window);
        window.display();
    }

    ImGui::SFML::Shutdown();
}
