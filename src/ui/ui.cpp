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
    if(!m_is_active)
      return;

    float ypos = (float)screenHeight * 4/5;
    bool result = GuiWindowBox({0.0f, ypos, (float)screenWidth, screenHeight - ypos}, "Menu");
  }

  void UIManager::OnRegister(std::vector<Entity*> *_entities_list) {m_entity_list = _entities_list;}

  Type UIManager::GetType() {return eUI;}

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
}