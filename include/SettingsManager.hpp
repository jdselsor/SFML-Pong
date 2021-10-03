#pragma once

#include <string>

namespace sfml_pong
{
    struct Settings
    {
        // Should know this, but forgot it and filled the logic tables for fun.
        
        // 1 is true and 0 is false.
        //
        // not 1 is 0.
        // not 0 is 1.

        // 1 and 1 is 1.
        // 1 and 0 is 0.
        // 0 and 1 is 0.
        // 0 and 0 is 0.

        // 1 or 1 is 1.
        // 1 or 0 is 1.
        // 0 or 1 is 1.
        // 0 or 0 is 0.

        // 1 xor 1 is 0.
        // 1 xor 0 is 1.
        // 0 xor 1 is 1.
        // 0 xor 0 is 0.

        // 1 -> 1 is 1.
        // 1 -> 0 is 0.
        // 0 -> 1 is 1.
        // 0 -> 0 is 1.

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
