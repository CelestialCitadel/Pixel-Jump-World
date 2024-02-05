#pragma once
#include <SFML/Graphics.hpp>

class Mario {
private:
    sf::Sprite marioSprite;
    sf::Texture marioTexture;

public:
    Mario();
    void draw(sf::RenderWindow& window);
};