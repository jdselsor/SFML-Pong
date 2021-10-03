#include <iostream>
#include <string>

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "SettingsManager.hpp"

int main ()
{
    std::cout << "Hello World - Build Chain Works" << std::endl;

    sfml_pong::Settings settings;
    sfml_pong::createSettings("./config.json", settings);
    uint32_t width, height;
    width = settings.width;
    height = settings.height;

    sf::RenderWindow window (sf::VideoMode (width, height), "My Window");

    while (window.isOpen())
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

        // Update Entities

        // Render Entities

        window.display();
    }

    return 0;
}
