#include <iostream>
#include "../headers/Mario.hpp"
#include "../headers/common.hpp"

Mario::Mario() :
    x(0.5f * SCREEN_WIDTH),
    y(0.5f * SCREEN_HEIGHT)
{

    if (!marioTexture.loadFromFile("resources/images/marioIdle.png")) {
        std::cout << "Error!";
    }

    else marioSprite.setTexture(marioTexture);
}

void Mario::draw(sf::RenderWindow& window) {
    marioSprite.setPosition(round(x), round(y));
    window.draw(marioSprite);
}