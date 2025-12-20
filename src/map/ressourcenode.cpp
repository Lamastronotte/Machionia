#include "ressourcenode.hpp"

namespace Entity
{
  /*
  eGOLD,
    eOIL,
    eMETAL
  */

  std::map<int, std::string> TypeToTexture;

  void Draw() // draw the right sprite
  {

  }
  void Update(float dt) // maybe animation
  {

  }

  Type RessourceNode::GetType() {return eRESSOURCE;}
};