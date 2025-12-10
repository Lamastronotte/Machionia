
#include "globals.hpp"

GlobalEntities* GlobalEntities::Register(Entity* _entity)
{
  m_entities.push_back(_entity);
  _entity->OnRegister(&m_entities);
  return this;
}

void GlobalEntities::Draw()
{
  for (auto& e : m_entities)
  {
    e->Draw();
  }
}

void GlobalEntities::Update()
{
  float Delta_Time = GetFrameTime();
  for (auto &e : m_entities)
  {
    e->Update(Delta_Time);
  }
}