#ifndef _Player_H_
#define _Player_H_

#include <SFML/Graphics.hpp>
#include <iostream>
#include <Windows.h>

class Player
{
private:
    sf::RenderWindow*             m_window;
    sf::Texture                   m_texture;
    sf::Sprite                    m_sprite;

public:
    Player(sf::RenderWindow* window);

    void                          update();
    void                          draw();
};

#endif //  _Player_H_