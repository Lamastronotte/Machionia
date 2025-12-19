#pragma once

// all of the includes of libraries
// stuff like asset loc and hardcoded values that DOESN'T CHANGE

#define NOMINMAX
#define WIN32_LEAN_AND_MEAN

// #include "spdlog/spdlog.h"
// #include "spdlog/sinks/basic_file_sink.h"

#include "raylib.h"
#include "rlgl.h"

// #include "enet/enet.h"

#include <array>
#include <vector>
#include <string>
#include <map>
#include <iostream> 
#include <filesystem>

#include "assets_loc.hpp"
#include "entity.hpp"
#include "globals.hpp"

// definitions in config.cpp
extern int screenWidth;
extern int screenHeight;