#pragma once

#include <string>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

namespace sfml_pong
{
    class Ball
    {
        public:
            // The ball constructor. It creates a new ball at the position x, y
            // and a radius.
            //
            // Parameter
            //      x (float): The x position of the ball.
            //      y (float): The y position of the ball.
            //      radius (float): The radius of the ball.
            Ball (float x, float y, float radius);

            // Renders the ball to the screen.
            //
            // Parameter
            //      window (&RenderWindow): the window to render the ball to.
            void render(sf::RenderWindow &window);

            // Updates the ball.
            void update();

            // Moves the fall using the shapes.move(x, y) function. This is
            // relative to the current position. It also updates the m_x, and
            // m_y variables.
            //
            // Parameter
            //      x (float): The x value to move the ball.
            //      y (float): The y value to move the ball.
            void move (float x, float y);

            // Sets the color of the ball.
            //
            // Parameter
            //      r (uint8_t): The red value of the color.
            //      g (uint8_t): The green value of the color.
            //      b (uint8_t): The blue value of the color.
            void setColor (uint8_t r, uint8_t g, uint8_t b);

            // Sets the direction of the ball. TODO: add check to insure x
            // and y are -1, 0, 1 only.
            //
            // Parameter
            //      x (float): The x direction for the ball.
            //      y (float): The y direction for the ball.
            void setDirection (float x, float y);

            // Sets the ball's speed. Will be used to speed up the ball.
            //
            // Parameter
            //      speed (float): The new speed for the ball.
            void setSpeed (float speed);

            sf::Vector2f getPosition() {return m_position;}
        private:
            sf::Vector2f m_position;
            float m_radius;

            sf::CircleShape m_circle;
            uint32_t m_color;

            sf::Vector2f m_direction;
            float m_speed;
    };

    class Paddle {
        public:
            Paddle (float x, float y, float width, float height);

            virtual void render (sf::RenderWindow &window);
            virtual void update ();

            virtual void move (float x, float y);

            void setColor (uint8_t r, uint8_t g, uint8_t b);

            sf::Vector2f getPosition ();
            sf::Vector2f getSize ();

            void setSpeed (float speed);
            float getSpeed ();
        protected:
            sf::Vector2f m_position;
            sf::Vector2f m_size;

            sf::RectangleShape m_rect;
            uint32_t m_color;

            float m_speed;
    };

    class AIPaddle : public Paddle {
        AIPaddle (float x, float y, float width, float height) : Paddle (x, y, width, height){};
    };
}
