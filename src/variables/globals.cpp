#include "globals.hpp"

// variable definition
GlobalAssets Global_Assets;


Texture* GlobalAssets::GetTexture(std::string id)
{
  return &m_textures[id];
}
Sound* GlobalAssets::GetSound(std::string id)
{
  return &m_sounds[id];
}

void GlobalAssets::Load()
{
  LoadFromFile(&Textures_Names, "./assets/textures");
  LoadFromFile(&Sounds_Names, "./assets/sfx");

  for (auto &name : Textures_Names)
  {
    this->m_textures[name.stem().string()] = LoadTexture(name.string().c_str());
  }

  for (auto &name : Sounds_Names)
  {
    this->m_sounds[name.stem().string()] = LoadSound(name.string().c_str());
  }
}

namespace Entity
{
  GlobalEntities Global_Entities;

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
};