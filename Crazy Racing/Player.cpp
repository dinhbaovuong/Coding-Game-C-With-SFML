#include "Player.h"

Player::Player(sf::RenderWindow* window)
{
    this->m_window = window;
    this->m_window->setMouseCursorVisible(false);

    this->m_texture.loadFromFile("Assets/Texture/Car_4.png");
    this->m_texture.setSmooth(true);

    this->m_sprite.setTexture(this->m_texture);
    this->m_sprite.setOrigin(this->m_texture.getSize().x / 2, this->m_texture.getSize().y / 2);
}

void Player::update()
{
    sf::Vector2i mouse_position = sf::Mouse::getPosition(*this->m_window);
    
    mouse_position.y = 500;
    if (mouse_position.x <= 0)
        mouse_position.x = 25;
    if (mouse_position.x >= 800)
        mouse_position.x = 775;

    this->m_sprite.setPosition(mouse_position.x, mouse_position.y);
}

void Player::draw()
{
    this->m_window->draw(this->m_sprite);
}