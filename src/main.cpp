#include <SFML/Graphics.hpp>
#include <imgui.h>
#include <imgui-SFML.h>
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

struct Troop
{
    std::string name;
    int attack;
    int life;
    int power;
    int quantity;
};

struct ResourceBonus
{
    int wood = 0;
    int stone = 0;
    int metal = 0;
    int food = 0;
    int gold = 0;
};

struct TargetData
{
    int defendersPower;
    ResourceBonus resourceBonus;
};

std::unordered_map<std::string, std::vector<TargetData>> targetDatabase;
std::vector<Troop> playerTroops = {
    {"Porter", 1, 45, 1, 0},
    {"Conscript", 10, 75, 1, 0},
    {"Spy", 5, 10, 2, 0},
    {"Halberdsman", 40, 150, 2, 0},
    {"Minotaur", 70, 225, 3, 0},
    {"Longbowman", 85, 75, 4, 0},
    {"Swift Strike Dragon", 150, 300, 5, 0},
    {"Battle Dragon", 300, 1500, 7, 0},
    {"Armored Transport", 5, 750, 6, 0},
    {"Giant", 1000, 4000, 9, 0},
    {"Fire Mirror", 1220, 1500, 10, 0}
};

std::string selectedTarget = "AnthropusCamp";
int selectedLevel = 1;
std::vector<std::string> targets = {"AnthropusCamp", "WildernessForest", "WildernessMountain", "WildernessHill", "WildernessLake"};
std::string battleOutcomeMessage = ""; // To display the outcome

void initializeTargetDatabase()
{
    targetDatabase["AnthropusCamp"] = {
        {1000, {0, 0, 0, 112500, 2500}},   // Level 1
        {2000, {0, 0, 0, 225000, 5000}},   // Level 2
        {3000, {0, 0, 0, 337500, 7500}},   // Level 3
        {4000, {0, 0, 0, 450000, 10000}},  // Level 4
        {5000, {0, 0, 0, 562500, 12500}},  // Level 5
        {6000, {0, 0, 0, 675000, 15000}},  // Level 6
        {7000, {0, 0, 0, 787500, 17500}},  // Level 7
        {8000, {0, 0, 0, 900000, 20000}},  // Level 8
        {9000, {0, 0, 0, 1012500, 22500}}, // Level 9
        {10000, {0, 0, 0, 1125000, 25000}} // Level 10
    };

    targetDatabase["WildernessForest"] = {
        {500, {10, 0, 0, 0, 0}}, {1000, {20, 0, 0, 0, 0}}, {1500, {30, 0, 0, 0, 0}}, {2000, {40, 0, 0, 0, 0}}, {2500, {50, 0, 0, 0, 0}}, {3000, {60, 0, 0, 0, 0}}, {3500, {70, 0, 0, 0, 0}}, {4000, {80, 0, 0, 0, 0}}, {4500, {90, 0, 0, 0, 0}}, {5000, {100, 0, 0, 0, 0}}};

    targetDatabase["WildernessMountain"] = {
        {500, {0, 10, 0, 0, 0}}, {1000, {0, 20, 0, 0, 0}}, {1500, {0, 30, 0, 0, 0}}, {2000, {0, 40, 0, 0, 0}}, {2500, {0, 50, 0, 0, 0}}, {3000, {0, 60, 0, 0, 0}}, {3500, {0, 70, 0, 0, 0}}, {4000, {0, 80, 0, 0, 0}}, {4500, {0, 90, 0, 0, 0}}, {5000, {0, 100, 0, 0, 0}}};

    targetDatabase["WildernessHill"] = {
        {500, {0, 0, 10, 0, 0}}, {1000, {0, 0, 20, 0, 0}}, {1500, {0, 0, 30, 0, 0}}, {2000, {0, 0, 40, 0, 0}}, {2500, {0, 0, 50, 0, 0}}, {3000, {0, 0, 60, 0, 0}}, {3500, {0, 0, 70, 0, 0}}, {4000, {0, 0, 80, 0, 0}}, {4500, {0, 0, 90, 0, 0}}, {5000, {0, 0, 100, 0, 0}}};

    targetDatabase["WildernessLake"] = {
        {500, {0, 0, 0, 10, 0}}, {1000, {0, 0, 0, 20, 0}}, {1500, {0, 0, 0, 30, 0}}, {2000, {0, 0, 0, 40, 0}}, {2500, {0, 0, 0, 50, 0}}, {3000, {0, 0, 0, 60, 0}}, {3500, {0, 0, 0, 70, 0}}, {4000, {0, 0, 0, 80, 0}}, {4500, {0, 0, 0, 90, 0}}, {5000, {0, 0, 0, 100, 0}}};
}

TargetData getTargetData(const std::string &targetType, int level)
{
    return targetDatabase[targetType][level - 1];
}

int calculateTotalCombatStrength(const std::vector<Troop> &troops)
{
    int totalCombatStrength = 0;
    for (const auto &troop : troops)
    {
        totalCombatStrength += troop.attack * troop.life * troop.power * troop.quantity;
    }
    return totalCombatStrength;
}

void displayTroopInputForm()
{
    ImGui::Begin("Troop Deployment Form");

    for (auto &troop : playerTroops)
    {
        ImGui::InputInt(troop.name.c_str(), &troop.quantity);
    }

    if (ImGui::BeginCombo("Target", selectedTarget.c_str()))
    {
        for (const auto &target : targets)
        {
            bool isSelected = (selectedTarget == target);
            if (ImGui::Selectable(target.c_str(), isSelected))
            {
                selectedTarget = target;
            }
            if (isSelected)
            {
                ImGui::SetItemDefaultFocus();
            }
        }
        ImGui::EndCombo();
    }

    ImGui::InputInt("Level", &selectedLevel);
    selectedLevel = std::max(1, std::min(selectedLevel, 10));

    if (ImGui::Button("Deploy"))
    {
        int playerCombatStrength = calculateTotalCombatStrength(playerTroops);
        TargetData target = getTargetData(selectedTarget, selectedLevel);
        bool victory = playerCombatStrength > target.defendersPower;
        battleOutcomeMessage = victory ? "Victory! " : "Defeat! ";
        battleOutcomeMessage += "Your power: " + std::to_string(playerCombatStrength) + " vs Enemy power: " + std::to_string(target.defendersPower) + ". ";

        if (victory)
        {
            battleOutcomeMessage += "Resources earned: Wood " + std::to_string(target.resourceBonus.wood) +
                                    ", Stone " + std::to_string(target.resourceBonus.stone) +
                                    ", Metal " + std::to_string(target.resourceBonus.metal) +
                                    ", Food " + std::to_string(target.resourceBonus.food) +
                                    ", Gold " + std::to_string(target.resourceBonus.gold) + ".";
        }
    }

    if (!battleOutcomeMessage.empty())
    {
        ImGui::Text("%s", battleOutcomeMessage.c_str());
    }

    ImGui::End();
}

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Battle Simulator");
    ImGui::SFML::Init(window);

    initializeTargetDatabase();

    sf::Clock deltaClock;
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
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
