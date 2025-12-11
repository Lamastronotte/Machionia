#pragma once
#include "config.hpp"

namespace Entity
{
/*
class for inheritance
*/
  class Entity
  {
    public:

      Entity();

      virtual void Draw();
      virtual void Update(float dt);

      virtual void OnRegister(std::vector<Entity*> *_entities_list);
  };
};