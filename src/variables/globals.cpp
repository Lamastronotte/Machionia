#include "globals.hpp"

// variable definition
GlobalAssets Global_Assets;

Camera2D* Global_Camera;

Player Local_Player;

Lang::LangSystem Global_Lang;

float needed_camera_move = 50.f;
float camera_speed = 450.f;

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
	m_layer_draw_map[_entity->GetDrawLayer()].push_back(_entity);
  _entity->OnRegister(&m_entities);
  return this;
}

void GlobalEntities::Draw()
{
  ClearBackground(BLACK);

  for (auto& [layer, bucket] : m_layer_draw_map)
  {
    for (Entity* e : bucket)
    {
      if (e->GetType() != Type::eUI)
        e->Draw();
    }
  }
}

void GlobalEntities::DrawUI()
{
  for (auto& e : m_entities)
  {
    if (e->GetType() == Type::eUI)
    {
      e->Draw();
    }
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