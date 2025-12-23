#pragma once

#include "config.hpp"

// global variables here with extern but defined in globals.cpp


class GlobalAssets;
class Player;

extern GlobalAssets Global_Assets;

extern Camera2D* Global_Camera;

extern Player Local_Player;

// amount of pixels needed for the ca
extern float needed_camera_move;
extern float camera_speed;

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

  void Load(); // can't use the constructor cuz it needs window initialisation
};

namespace Entity
{

  class Entity;
  class GlobalEntities;
  extern GlobalEntities Global_Entities;

  class GlobalEntities
  {
  public:

    /*
    can't put a definition in the globals.cpp file
    simple code to access the array simply like this : GlobalEntities[10]
    */
    Entity* operator[](std::size_t idx) const
    {
      return m_entities.at(idx);
    }

    /*
    i'll repeat but pass a reference when calling  -> ge.Register(&my_entity)
    Adds an entity to the array and call, pass the array to the entity and uses a callback from entity
    */
    GlobalEntities* Register(Entity* _entity);
    
    void Draw();
    void DrawUI();
    void Update();

  private:
    std::vector<Entity*> m_entities;
    std::map<int, std::vector<Entity*>> m_layer_draw_map;
  };
};