#include "Game.h"

Game::Game(sf::RenderWindow* window)
{
    this->m_window = window;

    this->m_player = new Player(this->m_window);

    this->m_texture_threat.loadFromFile("Assets/Texture/Car_2.png");

    this->m_threat.push_back(Threat(this->m_window, this->m_texture_threat));
}

void Game::update()
{
    this->m_player->update();

    if (this->m_threat.size() > 0)
    {
        for (std::list<Threat>::iterator it = this->m_threat.begin(); it != this->m_threat.end(); it++)
        {
            it->update();
        }
        if (this->m_threat.begin()->getPosition().y >= 500)
        {
            this->m_threat.pop_back();
            std::cout << "Delete";
        }
    }
}

void Game::draw()
{
    this->m_player->draw();

    if (this->m_threat.size() > 0)
    {
        for (std::list<Threat>::iterator it = this->m_threat.begin(); it != this->m_threat.end(); it++)
        {
            it->draw();
        }
    }
}