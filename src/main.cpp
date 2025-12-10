#include "config.hpp"

//----------------------------------------------------------------------------------
// Program main entry point
//----------------------------------------------------------------------------------
int main()
{
  spdlog::info("Welcome to spdlog!");

  // Initialization
  //--------------------------------------------------------------------------------------
  InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

  SetTargetFPS(60); // Set our game to run at 60 frames-per-second
  //--------------------------------------------------------------------------------------

  Entity myentity;

  Global_Entities.Register(&myentity);

  // Main game loop
  while (!WindowShouldClose()) // Detect window close button or ESC key
  {
    BeginDrawing();
    Global_Entities.Draw();
    EndDrawing();
  }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}