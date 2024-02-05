#include <array>
#include <chrono>
#include <SFML/Graphics.hpp>

#include "../headers/common.hpp"
#include "../headers/DrawMap.hpp"

void draw_map(sf::RenderWindow& i_window, const sf::Texture& i_map_texture, const Map& i_map)
{
    sf::Sprite cell_sprite(i_map_texture);

    for (unsigned short a = 0; a < i_map.size(); a++) 
    {
        for (unsigned short b = 0; b < i_map[a].size(); b++) 
        {
            if (Cell::Empty == i_map[a][b]) 
            {
                continue;
            }

            cell_sprite.setPosition(CELL_SIZE * a, CELL_SIZE * b);
            i_window.draw(cell_sprite);
        }
    }
}