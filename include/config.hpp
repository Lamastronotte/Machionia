#pragma once

// all of the includes of libraries
// stuff like asset loc and hardcoded values that DOESN'T CHANGE

<<<<<<< HEAD
#include "raylib.h"
#include "rlgl.h"

#define NOMINMAX
#define WIN32_LEAN_AND_MEAN
#define NOGDI
#define NOUSER

#include "spdlog/spdlog.h"
//#include "spdlog/sinks/basic_file_sink.h"
=======
#define NOMINMAX
#define WIN32_LEAN_AND_MEAN

#include "spdlog/spdlog.h"
#include "spdlog/sinks/basic_file_sink.h"

#include "raylib.h"
#include "rlgl.h"
>>>>>>> 84eabab4631653ac751af224845619a3c44157b2

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
#include "collider.hpp"

// definitions in config.cpp
extern int screenWidth;
<<<<<<< HEAD
extern int screenHeight;
extern float texture_size;// TODO set all rectangle source to use this instead of 100
=======
extern int screenHeight;
>>>>>>> 84eabab4631653ac751af224845619a3c44157b2
