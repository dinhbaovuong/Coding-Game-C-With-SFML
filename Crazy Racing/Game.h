#ifndef _Game_H_
#define _Game_H_

#include <SFML/Graphics.hpp>
#include <iostream>
#include <Windows.h>
#include "Player.h"

class Game
{
private:
    sf::RenderWindow*           m_window;
    Player*                     m_player;
public:
    Game(sf::RenderWindow* window);

    void                        update();
    void                        draw();
};

#endif //   _Game_H_