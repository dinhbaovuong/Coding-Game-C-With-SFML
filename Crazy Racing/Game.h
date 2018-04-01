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
    sf::Texture                 m_texture_threat_1;
    sf::Texture                 m_texture_threat_2;
    sf::Texture                 m_texture_threat_3;
    Player*                     m_player;

    sf::Clock                   m_clock;
    sf::Time                    m_time;

    std::list<Threat>           m_threat;

    unsigned int                m_score;

    sf::Font                    m_font;
    sf::Text                    m_text;

public:
    Game(sf::RenderWindow* window);

    void                        update();
    void                        draw();
};

#endif //   _Game_H_