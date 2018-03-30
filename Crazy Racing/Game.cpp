#include "Game.h"

Game::Game(sf::RenderWindow* window)
{
    this->m_window = window;

    this->m_player = new Player(this->m_window);
}

void Game::update()
{
    this->m_player->update();
}

void Game::draw()
{
    this->m_player->draw();
}