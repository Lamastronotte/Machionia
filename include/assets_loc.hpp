#pragma once

#include "config.hpp"

//

std::vector<std::string> Textures_Names;
std::vector<std::string> Sounds_Names;

// reference to the array and to the file
void LoadFromFile(std::vector<std::string>* input, std::string file);