#include <iostream>
#include <string>

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "SettingsManager.hpp"

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

        window.clear();

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        {
            gameRunning = false;
        }

        // Update Entities

        // Render Entities

        window.display();
    }

    return 0;
}
