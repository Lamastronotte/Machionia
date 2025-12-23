#include "ressourcenode.hpp"

namespace Entity
{
  /*
  eGOLD,
    eOIL,
    eMETAL
  */

  std::map<int, std::string> TypeToTexture;

  RessourceNode::RessourceNode()
  {
    m_pos = {0.f, 0.f};
    m_size = {50.f, 50.f};
    m_node_type = eNULL;
	}

  void RessourceNode::Draw() // draw the right sprite
  {
		Texture text = *Global_Assets.GetTexture(TypeToTexture.at(m_node_type));
    DrawTexturePro(text, Rectangle{0.f, 0.f, texture_size, texture_size}, {m_pos.x, m_pos.y, 50.f,  50.f}, {0.f, 0.f}, 0, WHITE);
  }
  void RessourceNode::Update(float dt) // maybe animation
  {

  }

  Type RessourceNode::GetType() {return eRESSOURCE;}
  int RessourceNode::GetDrawLayer() { return 2; }

};