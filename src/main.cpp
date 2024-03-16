#include <SFML/Graphics.hpp>
#include <imgui.h>
#include <imgui-SFML.h>

#include "GameSession.h"
#include "TargetData.h"
#include "EventHandling.h"
#include "Rendering.h"

const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;
const std::string WINDOW_TITLE = "Battle Simulator";

int main() {
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_TITLE);
    ImGui::SFML::Init(window);

    GameSession gameSession;
    initializeTargetDatabase();  // Ensure this function is defined and correctly initializes game data.
    sf::Clock deltaClock;

    while (window.isOpen()) {
        handleEvents(window, gameSession);

        sf::Time dt = deltaClock.restart();
        ImGui::SFML::Update(window, dt);

        gameSession.update(dt.asSeconds());

        render(window, gameSession);
    }

    ImGui::SFML::Shutdown();
    return 0;
}
