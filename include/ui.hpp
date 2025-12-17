#pragma once

#include "config.hpp"
namespace Entity
{
  /*
  big class to handle smaller ui
  */
  class UIManager: public Entity
  {
  public:
    UIManager();

    void Draw();
    void Update(float dt);
    void OnRegister(std::vector<Entity*> *_entities_list);
    Type GetType();
  };
};


