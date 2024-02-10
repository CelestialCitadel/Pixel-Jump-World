#include <array>
#include <chrono>
#include <SFML/Graphics.hpp>

#include "../headers/common.hpp"
#include "../headers/DrawMap.hpp"

void draw_map(sf::RenderWindow& window, const sf::Texture& floor_texture, const Map& map)
{
    sf::Sprite floor_sprite(floor_texture);

    for (unsigned short row = 0; row < map.size(); ++row)
    {
        for (unsigned short col = 0; col < map[row].size(); ++col)
        {
            if (map[row][col] == Cell::Floor)
            {
                floor_sprite.setPosition(col * CELL_SIZE, row * CELL_SIZE);

                window.draw(floor_sprite);
            }
        }
    }
}
