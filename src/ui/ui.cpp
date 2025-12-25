#include "ui.hpp"

#define RAYGUI_IMPLEMENTATION
#include "raygui.h"



namespace Entity
{

  UIManager::UIManager() {
    m_is_active = true;
  }

  void UIManager::Update(float dt) 
  {
    
    ShowEntityDetail();
  }

  void UIManager::Draw() {
    // draw a big square on bottom that is the root of ui (root (other)) + (popups)
    if (!m_is_active)
      return;

    float ypos = (float)screenHeight * 4 / 5;
    bool result = GuiWindowBox({ 0.0f, ypos, (float)screenWidth, screenHeight - ypos }, "Menu");

		DrawPlayerRessources(&Local_Player);
  }

  void UIManager::OnRegister(std::vector<Entity*> *_entities_list) {m_entity_list = _entities_list;}

  Type UIManager::GetType() {return eUI;}
  int UIManager::GetDrawLayer() { return 100; }

  Entity* UIManager::GetEntity(Vector2 pos, bool ismouse) {
    return nullptr;
  }

  void UIManager::ShowEntityDetail()
  {
    /*
    TODO PRINT ON SCREEN ENTITY TYPE WHEN CLICKED WITH MOUSE
    */

    // if click
    if(IsMouseButtonPressed(0))
    {
      // convert mouse coord to world pos
      Vector2 mouseWorld = GetScreenToWorld2D(GetMousePosition(), *Global_Camera);

      // check for every entity
      for(auto e: *m_entity_list)
      {

        // check if it has collider
        auto entity_cast = dynamic_cast<Collider*>(e);
        if(entity_cast != nullptr)
        {
          // get the rectangle collider
          auto rec = entity_cast->GetRectangle();
          
          // check if collision between mouse pos in world coords and rectangle collider
          if(CheckCollisionPointRec(mouseWorld, rec))
          {
            //spdlog::info("hit entity");
          }
          else
          {
            //spdlog::info("missed entity");
          }
        }
      }
    }
  }

  void UIManager::DrawPlayerRessources(Player* plr)
  {
    // draw on top right corner
    // draw from right to left
    
    // use a for loop with the function bellow
    
    for(int i = 1; i <= 3; i++)
    {
      float ressource_amount = plr->GetLocalRessource(i);
      std::ostringstream ressource_text;
      ressource_text << Global_Lang.get(RessourceTypeName.at(i)) << std::to_string(i) << ": " << std::setprecision(1) << ressource_amount;
      DrawText(ressource_text.str().c_str(), screenWidth - 200 - i * 150, 20, 20, WHITE);
		}
		//DrawText(Global_Lang.get("ressource.name.gold").c_str(), screenWidth - 200 - 4 * 150, 20, 20, WHITE);
    /*

        void DrawText(const char *text, int posX, int posY, int fontSize, Color color);       // Draw text (using default font)
    void DrawTextEx(Font font, const char *text, Vector2 position, float fontSize, float spacing, Color tint); // Draw text using font and additional parameters
    void DrawTextPro(Font font, const char *text, Vector2 position, Vector2 origin, float rotation, float fontSize, float spacing, Color tint); // Draw text using Font and pro parameters (rotation)
    void DrawTextCodepoint(Font font, int codepoint, Vector2 position, float fontSize, Color tint); // Draw one character (codepoint)
    void DrawTextCodepoints(Font font, const int *codepoints, int codepointCount, Vector2 position, float fontSize, float spacing, Color tint); // Draw multiple character (codepoint)
    */
  }
}