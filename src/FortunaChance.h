#ifndef FORTUNA_CHANCE_H
#define FORTUNA_CHANCE_H

#include <string>
#include <vector>
#include <SFML/Graphics.hpp>

class FortunaChance {
public:
    FortunaChance(sf::RenderWindow* window);
    ~FortunaChance();
    void display();

    //handle click event
    void doLeftClick(sf::Vector2f& mouse);

    int state;// state of fortuna
private:
    sf::RenderWindow* window;

    //for state 1
    sf::Texture* fortunaTexture;
    sf::Sprite* fortunaSprite;

    //button
    sf::Texture* fortunaTextureButton;
    sf::Sprite* fortunaSpriteButton;

    //for state 2
    sf::Texture* fortunaTexture2;
    sf::Sprite* fortunaSprite2;

    //button
    sf::Texture* fortunaTextureButton2;
    sf::Sprite* fortunaSpriteButton2;

    //for state 3
    sf::Texture* fortunaTexture3;
    sf::Sprite* fortunaSprite3;

    //button
    sf::Texture* fortunaTextureButton3;
    sf::Sprite* fortunaSpriteButton3;

    sf::Font font;
    sf::Text text;
};

#endif // GAME_SESSION_H
