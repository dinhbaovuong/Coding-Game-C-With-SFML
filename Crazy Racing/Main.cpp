#include <SFML/Graphics.hpp>
#include <iostream>
#include <Windows.h>
#include "Game.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(300, 500), "Crazy Racing", sf::Style::Close);
    window.setFramerateLimit(60);

    std::srand(time(NULL));

    Game game(&window);

    bool checkChooseWindow = true;

    //   Game Loop
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::LostFocus)
                checkChooseWindow = false;
            if (event.type == sf::Event::GainedFocus)
                checkChooseWindow = true;
        }
        if (checkChooseWindow)
        {
            window.clear();
            game.draw();
            if (!game.update())
            {
                window.close();
            }
            
            window.display();
        }
    }

    return EXIT_SUCCESS;
}