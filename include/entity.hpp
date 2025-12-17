#pragma once
#include "config.hpp"

namespace Entity
{
  enum Type
  {
    eNIL,
    eTROOP,
    eMAP,
    eUI,
    eCAM
  };

/*
class for inheritance
*/
  class Entity
  {
    public:

      Entity() {}

      virtual void Draw() {}
      virtual void Update(float dt) {}

      virtual void OnRegister(std::vector<Entity*> *_entities_list) {}

      virtual Type GetType() {return eNIL;}
  };
};