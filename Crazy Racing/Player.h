#ifndef _Player_H_
#define _Player_H_

#include <SFML/Graphics.hpp>
#include <iostream>
#include <Windows.h>

class Player
{
private:
    sf::RenderWindow*             m_window;
    sf::Texture                   m_texture_car;
    sf::Sprite                    m_sprite_car;

    sf::Texture                   m_texture_heart;
    sf::Sprite                    m_sprite_heart;

    int                           m_countHeart;

public:
    Player(sf::RenderWindow* window);

    void                          update();
    void                          draw();

    int&                          getCountHeart();
    sf::Vector2f                  getPosition();
};

#endif //  _Player_H_