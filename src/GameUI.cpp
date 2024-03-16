#include <imgui.h>

#include "GameUI.h"
#include "TargetData.h"

void displayTroopInputForm(std::vector<Troop> &playerTroops, std::string &selectedTarget, int &selectedLevel, std::vector<std::string> &targets, std::string &battleOutcomeMessage, PlayerResources &playerResources)
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
            playerResources.wood += target.resourceBonus.wood;
            playerResources.stone += target.resourceBonus.stone;
            playerResources.metal += target.resourceBonus.metal;
            playerResources.food += target.resourceBonus.food;
            playerResources.gold += target.resourceBonus.gold;
        }
    }

    if (!battleOutcomeMessage.empty())
    {
        ImGui::Text("%s", battleOutcomeMessage.c_str());
    }

    ImGui::End();

    playerResources.displayResources();
}
