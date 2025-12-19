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
    /*
    TODO PRINT ON SCREEN ENTITY TYPE WHEN CLICKED WITH MOUSE
    */

    if(IsMouseButtonPressed(0))
    {
      for(auto e: *m_entity_list)
      {
        if(e->GetType() == eMAP)
        {
          // spdlog::info("Found map");
          // you know it's extended by collider class
          // if(((CCollider*)e).GetCollision();)
        }
      }
    }
  }

  void UIManager::Draw() {
    // draw a big square on bottom that is the root of ui (root (other)) + (popups)
    if(!m_is_active)
      return;

    float ypos = screenHeight * 4/5;
    bool result = GuiWindowBox({0.0f, ypos, (float)screenWidth, screenHeight - ypos}, "Menu");
  }

  void UIManager::OnRegister(std::vector<Entity*> *_entities_list) {m_entity_list = _entities_list;}

  Type UIManager::GetType() {return eUI;}

  Entity* UIManager::GetEntity(Vector2 pos, bool ismouse) {
    return nullptr;
  }
}