#pragma once

// all of the includes of libraries
// stuff like asset loc and hardcoded values that DOESN'T CHANGE

#include "raylib.h"
#include "rlgl.h"

#define NOMINMAX
#define WIN32_LEAN_AND_MEAN
#define NOGDI
#define NOUSER

#include "spdlog/spdlog.h"
//#include "spdlog/sinks/basic_file_sink.h"

// #include "enet/enet.h"

#include <array>
#include <vector>
#include <string>
#include <map>
#include <iostream> 
#include <filesystem>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <stdlib.h>

#include "assets_loc.hpp"
#include "entity.hpp"
#include "globals.hpp"
#include "collider.hpp"

// definitions in config.cpp
extern int screenWidth;
extern int screenHeight;
extern float texture_size;// TODO set all rectangle source to use this instead of 100