#include <iostream>
#include <string>

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "SettingsManager.hpp"
#include "GameObject.hpp"

int main ()
{
    std::cout << "Hello World - Build Chain Works" << std::endl;

    uint8_t gameRunning = true;

    sfml_pong::Settings settings;
    sfml_pong::createSettings("./config.json", settings);
    uint32_t width, height;
    width = settings.width;
    height = settings.height;

    sf::ContextSettings conextSettings;
    conextSettings.antialiasingLevel = settings.antialiasing;

    sf::RenderWindow window (sf::VideoMode (width, height), "Super Pong", (settings.fullscreen == true) ? sf::Style::Fullscreen : sf::Style::Default, conextSettings);
    window.setVerticalSyncEnabled(settings.vSync);

    sfml_pong::Ball ball (width / 2 - 5, height / 2 - 5, 5.0f);

    sfml_pong::Paddle testPaddle (10, height / 2 - 50, 15, 100);

    sf::Font font;

    if (!font.loadFromFile("./assets/fonts/UbuntuMono-Regular.ttf"))
    {
        std::cout << "Error Loading Font" << std::endl;
    }

    sf::Text text;
    text.setFont(font);
    text.setCharacterSize(12);
    text.setFillColor (sf::Color (0, 255, 0));

    while (window.isOpen() && gameRunning)
    {
        sf::Event event;

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        {
            gameRunning = false;
        }

        window.clear();

        // Update Entities
        ball.update();
        testPaddle.update();

        sf::Vector2f ballPosition;
        ballPosition.x = ball.getPosition().x;
        ballPosition.y = ball.getPosition().y;

        sf::Vector2f playerPaddlePosition;
        playerPaddlePosition.x = testPaddle.getPosition().x;
        playerPaddlePosition.y = testPaddle.getPosition().y;

        text.setString (
            "Ball's Position (x, y): " + std::to_string(ballPosition.x) + ", " + std::to_string(ballPosition.y) +
            "\nPlayer Paddle Position (x, y): " + std::to_string(playerPaddlePosition.x) + ", " + std::to_string(playerPaddlePosition.y)
        );

        // Render Entities
        ball.render(window);
        testPaddle.render(window);

        window.draw(text);

        window.display();
    }

    return 0;
}
