#pragma once
#include "config.hpp"

namespace Entity
{

  // map to a name that maps to a texture

  enum RessourceNodeType
  {
    eNULL,
    eGOLD,
    eOIL,
    eMETAL
  };

  extern std::map<int, std::string> TypeToTexture;
  

  class RessourceNode: public Entity, public Collider
  {
    public:

      virtual void Draw(); // draw the right sprite
      virtual void Update(float dt); // maybe animation

      Type GetType();
  };
};