#include "ui.hpp"

namespace Entity
{

  UIManager::UIManager() {}

  void UIManager::Update(float dt) {}
  void UIManager::Draw() {DrawTexture(*Global_Assets.GetTexture("fodder"), 0, 0, WHITE);}

  void UIManager::OnRegister(std::vector<Entity*> *_entities_list) {}

  Type UIManager::GetType() {return eUI;}
}