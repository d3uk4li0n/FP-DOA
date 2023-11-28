#include <SFML/Graphics.hpp>

enum GameState
{
    MainMenu,
    Playing
};

int main()
{
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(800, 600), "Dragons of Atlantis");

    // Set the initial game state
    GameState gameState = MainMenu;

    // Font for text rendering
    sf::Font font;
    // Load font from the "font" folder
    if (!font.loadFromFile("../../src/font/Minecraft.ttf"))
    {
        // Handle font loading error
       return -1;
    }

    sf::Text menuTitleText;
    menuTitleText.setFont(font);
    menuTitleText.setString("Dragons of atlantis");
    menuTitleText.setCharacterSize(30);
    menuTitleText.setFillColor(sf::Color::White);
    menuTitleText.setPosition(250.0f, 50.0f);

    sf::Text menuContextText;
    menuContextText.setFont(font);
    menuContextText.setString("War is coming to Atlantis.\nSeventy thousand years ago, the ancient ones returned.\nThey wove the threads of life again\n and created the four tribes of Atlantis.\nNow these tribes must battle one another\n for their very survival.");
    menuContextText.setCharacterSize(24);
    menuContextText.setFillColor(sf::Color::White);
    menuContextText.setPosition(50.0f, 250.0f);

    sf::RectangleShape button(sf::Vector2f(200.0f, 50.0f));
    button.setPosition(50.0f, 500.0f);
    button.setFillColor(sf::Color(76, 186, 215));

    sf::Text buttonText;
    buttonText.setFont(font);
    buttonText.setString("Next");
    buttonText.setCharacterSize(20);
    buttonText.setFillColor(sf::Color::White);
    buttonText.setPosition(100.0f, 515.0f);
    // Start the game loop
    while (window.isOpen())
    {
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }

            // Switch to playing state when Enter key is pressed
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter && gameState == MainMenu)
            {
                gameState = Playing;
            }
            if (event.type == sf::Event::MouseButtonPressed)
            {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                sf::Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));

                if (button.getGlobalBounds().contains(mousePosF) && gameState == Playing)
                {
                    // Go to the next screen logic (update gameState or perform other actions)
                }
            }
        }

        // Update based on game state
        if (gameState == Playing)
        {
            // Update game logic here
        }

        // Clear screen
        window.clear();

        // Draw based on game state
        if (gameState == MainMenu)
        {
            window.draw(menuTitleText);
            window.draw(menuContextText);
            window.draw(button);
            window.draw(buttonText);        }
        else if (gameState == Playing)
        {
            // Draw game elements (excluding the player)
        }

        // Update the window
        window.display();
    }

    return 0;
}