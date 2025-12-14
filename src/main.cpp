// main includes and general stuff
#include "config.hpp"

// specific entities
#include "map.hpp"

//----------------------------------------------------------------------------------
// Program main entry point
//----------------------------------------------------------------------------------
int main()
{
  // spdlog::info("Welcome to spdlog!");

  // Initialization
  //--------------------------------------------------------------------------------------
  InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

  SetTargetFPS(60); // Set our game to run at 60 frames-per-second
  //--------------------------------------------------------------------------------------

  Global_Assets.Load();

  Entity::Map myentity;

  int map_data[] = {
    1, 0, 1, 2, 1,
    0, 1, 2, 1, 0,
    1, 2, 1, 0, 1,
    2, 1, 0, 1, 2,
    1, 0, 1, 2, 1
  };

  myentity.LoadMap(map_data, "map_debug", 100, 5);
  Entity::Global_Entities.Register(&myentity);

  // Main game loop
  while (!WindowShouldClose()) // Detect window close button or ESC key
  {
    BeginDrawing();
    Entity::Global_Entities.Draw();
    EndDrawing();
  }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}