#include <SFML/Graphics.hpp>
#include <imgui.h>
#include <imgui-SFML.h>
#include "PlayerResources.h"
#include "GameUI.h"
#include "TargetData.h"

std::string selectedTarget = "AnthropusCamp";
int selectedLevel = 1;
std::vector<std::string> targets = {"AnthropusCamp", "WildernessForest", "WildernessMountain", "WildernessHill", "WildernessLake"};
std::string battleOutcomeMessage = "";
PlayerResources playerResources;

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
            {
                window.close();
            }
        }
        sf::Time dt = deltaClock.restart();
        ImGui::SFML::Update(window, dt);

        playerResources.update(dt.asSeconds());

        displayTroopInputForm(playerTroops, selectedTarget, selectedLevel, targets, battleOutcomeMessage, playerResources);

        window.clear();
        ImGui::SFML::Render(window);
        window.display();
    }

    ImGui::SFML::Shutdown();
}
