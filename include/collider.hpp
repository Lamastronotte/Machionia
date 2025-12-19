#pragma once
#include "config.hpp"

namespace Entity
{
  class Collider
  {
    public:
      Vector2 m_pos;
      Vector2 m_size;
      Rectangle GetRectangle();
  };
};