// main includes and general stuff
#include "config.hpp"

// specific entities
#include "map.hpp"
#include "Camera.hpp"
#include "ui.hpp"
#include "ressourcenode.hpp"

//----------------------------------------------------------------------------------
// Program main entry point
//----------------------------------------------------------------------------------
int main()
{

  srand(time(0));
  // spdlog::info("Welcome to spdlog!");

  // Initialization
  //--------------------------------------------------------------------------------------
  InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");
  // ToggleBorderlessWindowed();
  screenWidth = GetScreenWidth();
  screenHeight = GetScreenHeight();
  // spdlog::info("Started game with a {}x{} window", screenWidth, screenHeight);
  // ToggleFullscreen();

  SetTargetFPS(60); // Set our game to run at 60 frames-per-second
  
  Camera2D default_camera = {0};
  default_camera.target = {0, 0};
  default_camera.offset = {0, 0};//{(float)screenWidth / 2.f, (float)screenHeight / 2.f};
  default_camera.rotation = 0.f;
  default_camera.zoom = 1.0f;
  Global_Camera = &default_camera;

  Global_Assets.Load();

  Entity::Map mymap;

  int map_data[] = {
    1, 0, 1, 2, 1,
    0, 1, 2, 1, 0,
    1, 2, 1, 0, 1,
    2, 1, 0, 1, 2,
    1, 0, 1, 2, 1
  };

  mymap.LoadMap(map_data, "map_debug", 100, 5);

  Entity::RessourceNodeManager rnm;
 
	rnm.LoadTextures();
	rnm.LoadNodes(&mymap, nullptr, 100);

  Entity::Camera mycamera;

  Entity::UIManager myui;

  Entity::Global_Entities.Register(&mymap)->Register(&mycamera)->Register(&myui);

  // Main game loop
  while (!WindowShouldClose()) // Detect window close button or ESC key
  {
    Entity::Global_Entities.Update();

    BeginDrawing();
      BeginMode2D(*Global_Camera);
        Entity::Global_Entities.Draw();
      EndMode2D();
    
			Entity::Global_Entities.DrawUI();

    EndDrawing();
  }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}