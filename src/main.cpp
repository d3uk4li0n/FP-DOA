#include <SFML/Graphics.hpp>

int main() {
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(800, 600), "Dragons of atlantis");

    // Player setup
    sf::RectangleShape player(sf::Vector2f(50.0f, 50.0f));
    player.setPosition(375.0f, 500.0f);
    player.setFillColor(sf::Color::Green);

    // Start the game loop
    while (window.isOpen()) {
        // Process events
        sf::Event event;
        while (window.pollEvent(event)) {
            // Close window: exit
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        // Move player with arrow keys
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && player.getPosition().x > 0) {
            player.move(-0.5f, 0.0f);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && player.getPosition().x < 750) {
            player.move(0.5f, 0.0f);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && player.getPosition().y < 550) {
            player.move(0.0f,0.5f);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && player.getPosition().y > 0) {
            player.move(0.0f,-0.5f);
        }

        // Clear screen
        window.clear();

        // Draw the player and the ball
        window.draw(player);

        // Update the window
        window.display();
    }

    return 0;
}