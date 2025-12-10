#pragma once

// all of the includes of libraries
// stuff like asset loc and hardcoded values that DOESN'T CHANGE

#define NOMINMAX
#define WIN32_LEAN_AND_MEAN
#include "spdlog/spdlog.h"

#include "raylib.h"

// #define RAYGUI_IMPLEMENTATION
// #include "raygui.h"

#include <array>
#include <vector>
#include <string>
#include <map>
#include <iostream> 
#include <filesystem>

#include "assets_loc.hpp"
#include "entity.hpp"