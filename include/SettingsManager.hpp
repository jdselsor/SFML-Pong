#pragma once

#include <string>

namespace sfml_pong
{
    struct Settings
    {
        uint8_t fullscreen;
        uint32_t width, height;
        uint32_t vSync;
        uint8_t antialiasing;
    };

    // Creates the settings structure from the json config file path.
    //
    // Parameter
    //      configPath (string): The path to the config file. Should be
    //                           "./config.json".
    //      settings (&Settings): A referance to a settings structure.
    //
    // Return
    //      unit8: Returns 0 if the settings structure is created.
    //             Returns 1 if the settings structure is not created.
    void createSettings (std::string configPath, Settings &settings);
}
