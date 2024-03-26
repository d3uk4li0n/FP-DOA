// Rendering.cpp
#include "Rendering.h"
#include <imgui-SFML.h>

void render(sf::RenderWindow& window, GameSession& gameSession) {
    window.clear();
    gameSession.displayUI();
    ImGui::SFML::Render(window);
    window.display();
}
