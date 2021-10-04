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

    sf::RenderWindow window (sf::VideoMode (width, height), "My Window", (settings.fullscreen == true) ? sf::Style::Fullscreen : sf::Style::Default, conextSettings);
    window.setVerticalSyncEnabled(settings.vSync);

    sfml_pong::Ball ball (width / 2 - 5, height / 2 - 5, 5.0f);

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

        // Render Entities
        ball.render(window);

        window.display();
    }

    return 0;
}
