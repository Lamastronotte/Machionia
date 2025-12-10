#pragma once
#include "config.hpp"
#include "entity.hpp"

// list of loaded assets, loaded entity

// a list for sfx and textures
class GlobalAssets
{
private:
  std::map<std::string, Texture> m_textures;
  std::map<std::string, Sound> m_sounds;
public:

  Texture* GetTexture(std::string id);
  Sound* GetSound(std::string id);

  void LoadTextures(std::vector<std::string>* names);
  void LoadSounds(std::vector<std::string> *names);
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
  void Update();

private:
  std::vector<Entity*> m_entities;
};