#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "GameObject.hpp"

sfml_pong::Ball::Ball (float x, float y, float radius)
{
    m_x = x;
    m_y = y;
    m_radius = radius;

    m_circle = sf::CircleShape(m_radius);
    m_circle.setPosition(m_x, m_y);

    m_speed = 2.0f;
    m_direction = sf::Vector2f (-1.0f, 0.0f);

    setColor(255, 255, 255);
}

void sfml_pong::Ball::render(sf::RenderWindow &window)
{
    window.draw(m_circle);
}

void sfml_pong::Ball::update ()
{
    //std::cout << "Ball Position (x, y): " << m_x << ", " << m_y << std::endl;
    if (m_x - m_radius < 0.0f || m_x > 800.0f - 2 * m_radius)
    {
        std::cout << "Ball Direction (x, y): " << m_direction.x << ", " << m_direction.y << std::endl;
        m_direction.x *= -1.0f;
    }

    move (m_direction.x * m_speed, m_direction.y * m_speed);
}

void sfml_pong::Ball::move (float x, float y)
{
    m_circle.move(x, y);
    m_x = m_circle.getPosition().x;
    m_y = m_circle.getPosition().y;
}

void sfml_pong::Ball::setColor(uint8_t r, uint8_t g, uint8_t b)
{
    m_circle.setFillColor(sf::Color(r, g, b));
}
