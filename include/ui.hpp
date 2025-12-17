#pragma once

#include "config.hpp"
namespace Ui
{
  /*
  big class to handle smaller ui
  */
  class UIManager: public Entity::Entity
  {
  public:
    UIManager();

    void Draw();
    void Update(float dt);
    void OnRegister(std::vector<Entity*> *_entities_list);
  };
};


