// main includes and general stuff
#include "config.hpp"

// specific entities
#include "map.hpp"

//----------------------------------------------------------------------------------
// Program main entry point
//----------------------------------------------------------------------------------
int main()
{
  spdlog::info("Welcome to spdlog!");

  // Initialization
  //--------------------------------------------------------------------------------------
  InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

  Entity::map_shader_id = rlLoadShaderCode(Entity::map_vertex_src, Entity::map_frag_src);

  SetTargetFPS(60); // Set our game to run at 60 frames-per-second
  //--------------------------------------------------------------------------------------

  Global_Assets.Load();

  Entity::Map mymap;
  mymap.LoadMap("", 0, 0);
  Entity::Global_Entities.Register(&mymap);

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