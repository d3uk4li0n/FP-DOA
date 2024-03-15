#include <SFML/Graphics.hpp>
#include <imgui.h>
#include <imgui-SFML.h>
#include "GameSession.h"
#include "TargetData.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Battle Simulator");
    ImGui::SFML::Init(window);

    GameSession gameSession;
    initializeTargetDatabase();
    sf::Clock deltaClock;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            ImGui::SFML::ProcessEvent(event);
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        sf::Time dt = deltaClock.restart();
        ImGui::SFML::Update(window, dt);

        gameSession.update(dt.asSeconds());
        gameSession.displayUI();

        window.clear();
        ImGui::SFML::Render(window);
        window.display();
    }

    ImGui::SFML::Shutdown();
}
