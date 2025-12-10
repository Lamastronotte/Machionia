#pragma once

#include "config.hpp"

extern std::vector<std::filesystem::path> Textures_Names;
extern std::vector<std::filesystem::path> Sounds_Names;

// reference to the array and to the file
void LoadFromFile(std::vector<std::filesystem::path> *input, std::string file);