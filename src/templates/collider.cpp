#include "collider.hpp"

namespace Entity
{
  Rectangle Collider::GetRectangle()
  {
    return {m_pos.x, m_pos.y, m_size.x, m_size.y};
  }
  
}