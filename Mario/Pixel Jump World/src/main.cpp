#include <array>
#include <chrono>
#include <SFML/Graphics.hpp>

#include "../headers/common.hpp"
#include "../headers/Mario.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH * SCREEN_RESIZE_FACTOR, SCREEN_HEIGHT * SCREEN_RESIZE_FACTOR), "Super Mario Bros!");
    //window.setView(sf::View(sf::FloatRect(0, -CELL_SIZE, CELL_SIZE * MAP_WIDTH, FONT_HEIGHT + (CELL_SIZE + 1) * MAP_HEIGHT)));

    unsigned lag = 0;
    std::chrono::time_point<std::chrono::steady_clock> prev_time;

    prev_time = std::chrono::steady_clock::now();
    sf::Color background_color = sf::Color(92, 148, 252, 1);

    sf::Texture map_texture;
    map_texture.loadFromFile("resources/Images/Map.png");

    Map map(SCREEN_WIDTH / CELL_SIZE);

    Mario mario;

    for (unsigned short a = 0; a < map.size(); a++)
    {
        for (unsigned short b = map[a].size() - 2; b < map[a].size(); b++)
        {
            map[a][b] = Cell::Wall;
        }
    }

    // ========================= Main game loop =========================
    while (window.isOpen())
    {
        unsigned dt = (unsigned)std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::steady_clock::now() - prev_time).count();
        lag += dt;
        prev_time += std::chrono::microseconds(dt);

        sf::Event event;
        while (lag >= FRAME_DURATION)
        {
            lag -= FRAME_DURATION;

            // ========================= Event loop =========================
            while (window.pollEvent(event))
            {
                switch (event.type)
                {
                case sf::Event::Closed:
                    window.close();
                    break;

                default:
                    break;
                }
            }
            // ========================= Update game state =========================


            if (FRAME_DURATION > lag)
            {
                // ========================= Render or Draw =========================
                window.clear(background_color);
                mario.draw(window);
                mario.update();
                window.display();

            }
        }
    }

    return 0;
}
