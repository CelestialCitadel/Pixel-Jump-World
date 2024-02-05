#pragma once
#include <SFML/Graphics.hpp>

class Mario {
private:
    float x;
    float y;

    sf::Sprite marioSprite;
    sf::Texture marioTexture;

public:
    Mario();
    void draw(sf::RenderWindow& window);
};