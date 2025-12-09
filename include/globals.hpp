#pragma once
#include "config.hpp"
#include "entity.hpp"

// list of loaded assets, loaded entity

class GlobalAssets
{

};

class GlobalEntities
{
public:
  Entity* operator[](std::size_t idx) const
  {
    return m_entities.at(idx);
  }

  // i'll repeat but pass a reference when calling  -> ge.Register(&my_entity)
  GlobalEntities* Register(Entity* _entity);

  void Draw();

private:
  std::vector<Entity*> m_entities;
};