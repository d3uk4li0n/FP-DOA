// EventHandling.cpp
#include "EventHandling.h"
#include <imgui.h>
#include <imgui-SFML.h>
#include <iostream>

void handleEvents(sf::RenderWindow& window, GameSession& gameSession) {
    sf::Event event;
    while (window.pollEvent(event)) {
        ImGui::SFML::ProcessEvent(event);

        if (event.type == sf::Event::Closed) {
            window.close();
        }

        // Add more event handling as needed

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            // transform the mouse position from window coordinates to world coordinates
            sf::Vector2f mouse = window.mapPixelToCoords(sf::Mouse::getPosition(window));
            gameSession.doLeftClick(mouse);
        }
    }
}
