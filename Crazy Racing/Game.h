#ifndef _Game_H_
#define _Game_H_

#include <SFML/Graphics.hpp>
#include <iostream>
#include <Windows.h>
#include "Player.h"
#include "Threat.h"
#include <list>

class Game
{
private:
    sf::RenderWindow*           m_window;
    sf::Texture                 m_texture_threat;
    Player*                     m_player;


    std::list<Threat>           m_threat;

public:
    Game(sf::RenderWindow* window);

    void                        update();
    void                        draw();
};

#endif //   _Game_H_