#pragma once
#include "config.hpp"
#include "map.hpp"

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

		int m_node_type;
  };

  /*
  loads with 2 maps : a collision box and a mask, place nodes on collision box and erase thos with mask
  the collision box is the terrain and the mask is the path for the troops
  */
  class RessourceNodeManager 
  {
  public:
    static void LoadNodes(Map* area, Map* mask, float frequency)
    {

    }
  };
};