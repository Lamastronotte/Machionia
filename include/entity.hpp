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
    eCAM,
    eRESSOURCE
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

      // callback when entity is added to the vector
      virtual void OnRegister(std::vector<Entity*> *_entities_list) {}

      virtual Type GetType() {return eNIL;}
      virtual int GetDrawLayer() { return 0; }
  };
};