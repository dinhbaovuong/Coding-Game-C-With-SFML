#include <SFML/Graphics.hpp>
#include <iostream>
#include <Windows.h>
#include "Game.h"

//int main()
//int WINAPI WinMain( _In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nShowCmd )
int WINAPI WinMain( _In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nShowCmd )
{
    sf::RenderWindow window(sf::VideoMode(300, 500), "Crazy Racing", sf::Style::Close);
    window.setFramerateLimit(60);

    //   Set Icon for window
    sf::Image Icon;
    Icon.loadFromFile("Assets/Texture/Icon.png");
    window.setIcon(Icon.getSize().x, Icon.getSize().y, Icon.getPixelsPtr());

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
                break;
            }
            window.display();
        }
    }

    

    return EXIT_SUCCESS;
}