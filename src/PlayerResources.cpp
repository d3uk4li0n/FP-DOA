#include "PlayerResources.h"

PlayerResources::PlayerResources() 
    : wood(0), stone(0), metal(0), food(0), gold(0), updateTimer(0.0f)
{
}

void PlayerResources::increaseResources(int amount)
{
    wood += amount;
    stone += amount;
    metal += amount;
    food += amount;
    gold += amount;
}

void PlayerResources::displayResources()
{
    ImGui::Begin("Player Resources");
    ImGui::Text("Wood: %d", wood);
    ImGui::Text("Stone: %d", stone);
    ImGui::Text("Metal: %d", metal);
    ImGui::Text("Food: %d", food);
    ImGui::Text("Gold: %d", gold);
    ImGui::End();
}

void PlayerResources::update(float deltaTime)
{
    updateTimer += deltaTime;
    if (updateTimer >= 5.0f) // Every 5 seconds
    {
        increaseResources(5);
        updateTimer -= 5.0f;
    }
}
