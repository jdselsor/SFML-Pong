#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "GameObject.hpp"

sfml_pong::Ball::Ball (float x, float y, float radius)
{
    m_position.x = x;
    m_position.y = y;
    m_radius = radius;

    m_circle = sf::CircleShape(m_radius);
    m_circle.setPosition(m_position.x, m_position.y);

    m_speed = 2.0f;
    m_direction = sf::Vector2f (1.0f, 1.0f);

    setColor(255, 255, 255);
}

void sfml_pong::Ball::render(sf::RenderWindow &window)
{
    window.draw(m_circle);
}

void sfml_pong::Ball::update ()
{
    // Detect screen edges. TODO: Make screen width and height grab from the
    // settings struct. Test for direction switching.
    // deminsion - radius < 0.0f or diminsion > screen_dimension - 2 * radius
    if (m_position.x - m_radius < 0.0f || m_position.x > 800.0f - 2 * m_radius)
    {
        m_direction.x *= -1.0f;
    }

    if (m_position.y - m_radius < 0.0f || m_position.y > 600.0f - 2 * m_radius)
    {
        m_direction.y *= -1.0f;
    }

    move (m_direction.x * m_speed, m_direction.y * m_speed);
}

void sfml_pong::Ball::move (float x, float y)
{
    m_circle.move(x, y);
    m_position.x = m_circle.getPosition().x;
    m_position.y = m_circle.getPosition().y;
}

void sfml_pong::Ball::setColor(uint8_t r, uint8_t g, uint8_t b)
{
    m_circle.setFillColor(sf::Color(r, g, b));
}

sfml_pong::Paddle::Paddle (float x, float y, float width, float height)
{
    m_position.x = x;
    m_position.y = y;
    m_size.x = width;
    m_size.y = height;

    m_rect = sf::RectangleShape(m_size);
    m_rect.setPosition(m_position);

    m_speed = 3.5f;
}

void sfml_pong::Paddle::render (sf::RenderWindow &window)
{
    window.draw(m_rect);
}

void sfml_pong::Paddle::update ()
{
    uint8_t canMove = 1;

    if (m_position.y < 0)
    {
        canMove = 0;
    }

    if (m_position.y > 800)
    {
        canMove = 0;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && canMove)
    {
        move(0.0f, -m_speed);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && canMove)
    {
        move(0.0f, m_speed);
    }

    canMove = 1;
}

void sfml_pong::Paddle::move (float x, float y)
{
    m_rect.move(x, y);
    m_position.x = m_rect.getPosition().x;
    m_position.y = m_rect.getPosition().y;
}

sf::Vector2f sfml_pong::Paddle::getPosition ()
{
    return m_position;
}
