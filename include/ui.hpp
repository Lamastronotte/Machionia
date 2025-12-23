#pragma once

#include "config.hpp"
#include "map.hpp"

namespace Entity
{
  

  /*
  big class to handle smaller ui
  */
  class UIManager: public Entity
  {
  public:
    UIManager();

    void Draw();
    void Update(float dt);
    void OnRegister(std::vector<Entity*> *_entities_list);
    Type GetType();
    int GetDrawLayer();

  private:
    
    bool m_is_active;

    // returns an entity at a given pos
    // if ismouse, the coords are transformed from screen pos
    Entity* GetEntity(Vector2 pos, bool ismouse);
    std::vector<Entity*> *m_entity_list;

    void ShowEntityDetail();
		void DrawPlayerRessources(Player* plr);
  };
};


