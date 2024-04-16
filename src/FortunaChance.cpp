#include "FortunaChance.h"

FortunaChance::FortunaChance(sf::RenderWindow* window) : window(window), state(0)
{
    fortunaTexture = new sf::Texture();
    fortunaTexture->loadFromFile("..\\images\\doa_fortuna_screen1.png");
    fortunaSprite = new sf::Sprite(*fortunaTexture);

    fortunaTextureButton = new sf::Texture();
    fortunaTextureButton->loadFromFile("..\\images\\play_for_free.png");
    fortunaSpriteButton = new sf::Sprite(*fortunaTextureButton);
    fortunaSpriteButton->setPosition(382, 239);

    fortunaTexture2 = new sf::Texture();
    fortunaTexture2->loadFromFile("..\\images\\doa_fortuna_screen2.png");
    fortunaSprite2 = new sf::Sprite(*fortunaTexture2);

    fortunaTextureButton2 = new sf::Texture();
    fortunaTextureButton2->loadFromFile("..\\images\\choose_button.png");
    fortunaSpriteButton2 = new sf::Sprite(*fortunaTextureButton2);
    fortunaSpriteButton2->setPosition(465, 100);

    fortunaTexture3 = new sf::Texture();
    fortunaTexture3->loadFromFile("..\\images\\popup_window.png");
    fortunaSprite3 = new sf::Sprite(*fortunaTexture3);
    fortunaSprite3->setPosition(300, 200);

    fortunaTextureButton3 = new sf::Texture();
    fortunaTextureButton3->loadFromFile("..\\images\\fortuna_ok_button.png");
    fortunaSpriteButton3 = new sf::Sprite(*fortunaTextureButton3);
    fortunaSpriteButton3->setPosition(fortunaSprite3->getPosition().x + 115, fortunaSprite3->getPosition().y + 217);

    font.loadFromFile("../font/Minecraft.ttf");
   
    // select the font
    text.setFont(font); // font is a sf::Font
    // set the color
    text.setFillColor(sf::Color::Blue);

    // set the character size
    text.setCharacterSize(16); // in pixels, not points!
}

FortunaChance::~FortunaChance()
{
    delete fortunaSprite;
    delete fortunaTexture;
    delete fortunaSpriteButton;
    delete fortunaTextureButton;

    delete fortunaSprite2;
    delete fortunaTexture2;
    delete fortunaSpriteButton2;
    delete fortunaTextureButton2;

    delete fortunaSprite3;
    delete fortunaTexture3;
    delete fortunaSpriteButton3;
    delete fortunaTextureButton3;
}

void FortunaChance::display()
{
    if (state == 0)
    {
        window->draw(*fortunaSprite);
        window->draw(*fortunaSpriteButton);
    }
    else if (state == 1) {
        window->draw(*fortunaSprite2);
        window->draw(*fortunaSpriteButton2);
    }
    else if (state == 2) {
        window->draw(*fortunaSprite2);
        window->draw(*fortunaSpriteButton2);
        window->draw(*fortunaSprite3);
        window->draw(*fortunaSpriteButton3);

        // set the string to display
        text.setString("You have received 11 Million Iron");
        text.setPosition(fortunaSprite3->getPosition().x + 10, fortunaSprite3->getPosition().y + 100);
        window->draw(text);
    }
    else {
        window->clear();
    }
}

void FortunaChance::doLeftClick(sf::Vector2f& mouse)
{
    if (state == 0)
    {
        // retrieve the bounding box of the sprite
        sf::FloatRect bounds = fortunaSpriteButton->getGlobalBounds();

        // hit
        if (bounds.contains(mouse)) //fortunaSpriteButton ?
        {
            state = 1;
        }
    }
    else if (state == 1)
    {
        sf::FloatRect bounds = fortunaSpriteButton2->getGlobalBounds();

        // hit
        if (bounds.contains(mouse)) //choose button ?
        {
            state = 2;
        }
    }
    else if (state == 2)
    {
        sf::FloatRect bounds = fortunaSpriteButton3->getGlobalBounds();

        // hit
        if (bounds.contains(mouse)) //choose button ?
        {
            state = 3;
        }
    }
}
