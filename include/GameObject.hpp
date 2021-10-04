#pragma once

#include <string>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

namespace sfml_pong{
    // This should be a generic paddle. The Player paddle should inherit from this.
    class Paddle
    {
        public:
            // The paddle constructor. It creates a new paddle at the position x, y with a size of width height.
            //
            // Parameter
            //      x (float): The x position of the paddle.
            //      y (float): The y position of the paddle.
            //      width (float): The width of the paddle.
            //      height (float): The height of the paddle.
            Paddle (float x, float y, float width, float height) : m_x(x), m_y(y), m_width(width), m_height(height) {};

            void render ();
            void update ();
        private:
            float m_x, m_y;
            float m_width, m_height;
    };

    class Ball
    {
        public:
            // The ball constructor. It creates a new ball at the position x, y and a radius.
            //
            // Parameter
            //      x (float): The x position of the ball.
            //      y (float): The y position of the ball.
            //      radius (float): The radius of the ball.
            Ball (float x, float y, float radius);

            void render(sf::RenderWindow &window);
            void update();

            void move (float x, float y);
            void setColor (uint8_t r, uint8_t g, uint8_t b);

            void setDirection (float x, float y);
            void setSpeed (float speed);
        private:
            float m_x, m_y;
            float m_radius;

            sf::CircleShape m_circle;
            uint32_t m_color;

            sf::Vector2f m_direction;
            float m_speed;
    };
}
