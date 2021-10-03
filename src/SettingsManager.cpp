#include <iostream>
#include <fstream>
#include <string>

#include <jsoncpp/json/json.h>

#include "SettingsManager.hpp"

void sfml_pong::createSettings (std::string configPath, Settings &settings)
{
    std::ifstream ifs (configPath);

    Json::Reader reader;
    Json::Value obj;

    reader.parse (ifs, obj);

    settings.fullscreen = obj["fullscreen"].asUInt();
    settings.width = obj["width"].asUInt();
    settings.height = obj["height"].asUInt();
    settings.vSync = obj["vSync"].asUInt();
    settings.antialiasing = obj["antialiasing"].asUInt();

    std::cout << "Fullscreen: " << std::to_string (settings.fullscreen) << std::endl;
    std::cout << "Width, Height: " << std::to_string (settings.width) << ", " << std::to_string (settings.height) << std::endl;
    std::cout << "vSync: " << std::to_string(settings.vSync) << std::endl;
    std::cout << "Antialiasing: " << std::to_string(settings.antialiasing) << std::endl;
}
