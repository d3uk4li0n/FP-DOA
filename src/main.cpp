// Third-party libraries
#include <SFML/Graphics.hpp>
#include <imgui.h>
#include <imgui-SFML.h>

// Project header files
#include "GameSession.h"
#include "TargetData.h"

// Window size constants
const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;
const std::string WINDOW_TITLE = "Battle Simulator";

int main() {
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_TITLE);
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
