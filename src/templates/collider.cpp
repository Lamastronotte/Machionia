#include "collider.hpp"

namespace Entity
{
  bool CCollider::GetCollision(CCollider obj)
  {
    /*
    4 statements : 
     bool CheckCollisionRecs(Rectangle rec1, Rectangle rec2);                                           // Check collision between two rectangles
    bool CheckCollisionCircles(Vector2 center1, float radius1, Vector2 center2, float radius2);        // Check collision between two circles
    bool CheckCollisionCircleRec(Vector2 center, float radius, Rectangle rec);
    */
   
    // both are rectangles
  //  if(obj.m_collider.m_collision_type == ERectangle && m_collider.m_collision_type == ERectangle)
  //  {
  //   // return CheckCollisionRecs(obj.m_collider.m_collision, m_collider.m_collision);  
  //  }

   if(obj.m_collider.m_collision_type == ECircle && m_collider.m_collision_type == ECircle)
   {
    return CheckCollisionCircles(obj.m_collider.m_pos, obj.m_collider.m_radius, m_collider.m_pos, m_collider.m_radius);
   }

   if(obj.m_collider.m_collision_type == ERectangle && m_collider.m_collision_type == ECircle)
   {
    return CheckCollisionCircleRec(m_collider.m_pos, m_collider.m_radius, obj.m_collider.m_collision);
   }

   if(obj.m_collider.m_collision_type == ECircle && m_collider.m_collision_type == ERectangle)
   {
    return CheckCollisionCircleRec(obj.m_collider.m_pos, obj.m_collider.m_radius, m_collider.m_collision);
   }
   return false;
  }

  void CCollider::CalculateRectangle()
  {
    m_collider.m_collision = {m_collider.m_pos.x, m_collider.m_pos.y, m_collider.m_size.x, m_collider.m_size.y};
  }

  
}