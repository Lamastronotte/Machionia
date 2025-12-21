#include "ressourcenode.hpp"

namespace Entity
{
  /*
  eGOLD,
    eOIL,
    eMETAL
  */

  std::map<int, std::string> TypeToTexture;

<<<<<<< HEAD
  void RessourceNode::Draw() // draw the right sprite
  {
		static Texture text = *Global_Assets.GetTexture(TypeToTexture.at(m_node_type));
    DrawTexturePro(text, Rectangle{0.f, 0.f, texture_size, texture_size}, {m_pos.x, m_pos.y, 250.f, 250.f}, {0.f, 0.f}, 0, WHITE);
  }
  void RessourceNode::Update(float dt) // maybe animation
=======
  void Draw() // draw the right sprite
  {

  }
  void Update(float dt) // maybe animation
>>>>>>> 84eabab4631653ac751af224845619a3c44157b2
  {

  }

  Type RessourceNode::GetType() {return eRESSOURCE;}
<<<<<<< HEAD

=======
>>>>>>> 84eabab4631653ac751af224845619a3c44157b2
};