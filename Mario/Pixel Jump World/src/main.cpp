#include <chrono>
#include <SFML/Graphics.hpp>

#include "../headers/common.hpp"
#include "../headers/Mario.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH * SCREEN_RESIZE_FACTOR, SCREEN_HEIGHT * SCREEN_RESIZE_FACTOR), "Super Mario Bros!");
    //window.setView(sf::View(sf::FloatRect(0, -CELL_SIZE, CELL_SIZE * MAP_WIDTH, FONT_HEIGHT + (CELL_SIZE + 1) * MAP_HEIGHT)));

    sf::CircleShape circle(50.f);
    circle.setFillColor(sf::Color::Red);
    circle.setPosition(sf::Vector2f(0.f, 0.f));

    unsigned lag = 0;
    std::chrono::time_point<std::chrono::steady_clock> prev_time;

    prev_time = std::chrono::steady_clock::now();

    Mario mario;

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
                window.clear(sf::Color(0,219,255));
                mario.draw(window);
                window.display();

            }
        }
    }

    return 0;
}
