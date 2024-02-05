#include <iostream>
#include "../headers/Mario.hpp"
#include "../headers/common.hpp"

Mario::Mario() :
    x(1.0f * SCREEN_WIDTH),
    y(1.0f * SCREEN_HEIGHT)
{

    if (!marioTexture.loadFromFile("resources/images/marioIdle.png")) {
        std::cout << "Error!";
    }

    else marioSprite.setTexture(marioTexture);
}

void Mario::draw(sf::RenderWindow& window) {
    marioSprite.setPosition(round(x), round(y));
    marioSprite.setScale(sf::Vector2f(4.0f, 4.0f));
    window.draw(marioSprite);
}

void Mario::update()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        x -= MARIO_SPEED;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        x += MARIO_SPEED;
    }
}