#pragma once
#include "config.hpp"

namespace Entity
{

  enum ECollision
  {
    ENULL,
    ERectangle,
    ECircle
  };

  struct SCollider
  {
    Vector2 m_pos;
      Vector2 m_size;
      float m_radius;
      int m_collision_type;
      Rectangle m_collision;
  };

  /*
  Just adds pos and size
  */
  class CCollider: public Entity
  {
    public:
      SCollider m_collider;

      bool GetCollision(SCollider obj);
      void CalculateRectangle();
  };
};