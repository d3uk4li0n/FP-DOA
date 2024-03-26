// EventHandling.cpp
#include "EventHandling.h"
#include <imgui.h>
#include <imgui-SFML.h>

void handleEvents(sf::RenderWindow& window, GameSession& gameSession) {
    sf::Event event;
    while (window.pollEvent(event)) {
        ImGui::SFML::ProcessEvent(event);

        if (event.type == sf::Event::Closed) {
            window.close();
        }

        // Add more event handling as needed
    }
}
