#include "Game.h"

Game::Game(sf::RenderWindow* window) : m_score(0)
{
    this->m_window = window;

    this->m_player = new Player(this->m_window);

    this->m_texture_threat_1.loadFromFile("Assets/Texture/Car_1.png");
    this->m_texture_threat_1.setSmooth(true);

    this->m_texture_threat_2.loadFromFile("Assets/Texture/Car_2.png");
    this->m_texture_threat_2.setSmooth(true);

    this->m_texture_threat_3.loadFromFile("Assets/Texture/Car_3.png");
    this->m_texture_threat_3.setSmooth(true);

    this->m_threat.push_back(Threat(this->m_window, this->m_texture_threat_1));

    this->m_font.loadFromFile("Assets/Font/MarkerFelt.ttf");
    this->m_text.setFont(this->m_font);
    this->m_text.setString("Score: ");
    this->m_text.setCharacterSize(15);
    this->m_text.setPosition(200, 0);
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

        int x = abs(this->m_player->getPosition().x - this->m_threat.begin()->getPosition().x);
        int y = abs(this->m_player->getPosition().y - this->m_threat.begin()->getPosition().y);

        if (x <= 45 && y <= 95)
        {
            //std::cout << "Va cham\n";
            this->m_threat.pop_front();
            this->m_score += 10;
        }
        
        if (this->m_threat.size() > 0 && this->m_threat.begin()->getPosition().y >= 500)
        {
            this->m_threat.pop_front();
            //std::cout << "Delete\n";
        }
    }
    //std::cout << "Score: " << this->m_score << std::endl;
    this->m_time = this->m_clock.getElapsedTime();

    if (this->m_time.asSeconds() > 0.5)
    {
        switch (std::rand() % 3)
        {
        case 0:
            this->m_threat.push_back(Threat(this->m_window, this->m_texture_threat_1));
            break;
        case 1:
            this->m_threat.push_back(Threat(this->m_window, this->m_texture_threat_2));
            break;
        case 2:
            this->m_threat.push_back(Threat(this->m_window, this->m_texture_threat_1));
            break;
        }
        
        this->m_clock.restart();
    }

    this->m_text.setString("Score: " + std::to_string(this->m_score));
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

    this->m_window->draw(this->m_text);
}